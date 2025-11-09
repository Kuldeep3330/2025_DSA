# Chronos - Job Scheduler System
## High-Level Design Document

---

## 1. System Architecture & Components

### Core Components

```
┌─────────────────────────────────────────────────────────────────┐
│                         API Gateway / Load Balancer              │
└────────────────────────────┬────────────────────────────────────┘
                             │
        ┌────────────────────┼────────────────────┐
        │                    │                    │
┌───────▼────────┐  ┌────────▼────────┐  ┌───────▼────────┐
│  Job Service   │  │  Scheduler      │  │  Monitoring    │
│  (REST API)    │  │  Service        │  │  Service       │
└───────┬────────┘  └────────┬────────┘  └───────┬────────┘
        │                    │                    │
        └────────────────────┼────────────────────┘
                             │
        ┌────────────────────┼────────────────────┐
        │                    │                    │
┌───────▼────────┐  ┌────────▼────────┐  ┌───────▼────────┐
│  Message Queue │  │  Redis Cache    │  │  PostgreSQL    │
│  (RabbitMQ/    │  │  - Job Status   │  │  - Job Metadata│
│   Kafka)       │  │  - Locks        │  │  - User Data   │
└───────┬────────┘  └─────────────────┘  └────────────────┘
        │
┌───────▼────────────────────────────────────────────────────┐
│              Worker Pool (Horizontal Scaling)               │
│  ┌─────────┐  ┌─────────┐  ┌─────────┐  ┌─────────┐      │
│  │Worker 1 │  │Worker 2 │  │Worker 3 │  │Worker N │      │
│  └─────────┘  └─────────┘  └─────────┘  └─────────┘      │
└────────────────────────────────────────────────────────────┘
```

### Component Descriptions

**1. API Gateway / Load Balancer**
- Entry point for all client requests
- Routes traffic to appropriate services
- Handles authentication & rate limiting

**2. Job Service (REST API)**
- Handles job submission, cancellation, rescheduling
- Validates job payloads and schedules
- Stores job metadata in PostgreSQL

**3. Scheduler Service**
- Polls database for due jobs (using cron-like mechanism)
- Pushes jobs to message queue at scheduled time
- Manages recurring job schedules
- Uses distributed locks (Redis) to prevent duplicate scheduling

**4. Message Queue (RabbitMQ/Kafka)**
- Decouples job submission from execution
- Ensures reliable job delivery
- Supports priority queues for urgent jobs
- Dead Letter Queue (DLQ) for failed jobs

**5. Worker Pool**
- Consumes jobs from message queue
- Executes job logic
- Updates job status in Redis & PostgreSQL
- Implements retry logic with exponential backoff

**6. Monitoring Service**
- Tracks job execution metrics
- Monitors system health
- Sends notifications on failures
- Aggregates logs for analysis

**7. Redis Cache**
- Stores real-time job status
- Distributed locks for scheduler
- Rate limiting data
- TTL-based cache for frequently accessed data

**8. PostgreSQL Database**
- Primary data store for job metadata
- User information
- Job execution history
- ACID compliance for critical operations

### Technology Stack
- **Backend**: Node.js / Python (FastAPI)
- **Message Queue**: RabbitMQ (simpler) or Kafka (high throughput)
- **Cache**: Redis
- **Database**: PostgreSQL
- **Containerization**: Docker
- **Orchestration**: Kubernetes (for scaling)

### Scalability Considerations

**Horizontal Scaling:**
- **Worker Pool**: Add more workers to handle increased load
- **Scheduler Service**: Multiple instances with leader election (Redis locks)
- **API Service**: Stateless design allows easy replication behind load balancer

**Database Scaling:**
- Read replicas for PostgreSQL
- Partitioning job tables by date/status
- Archive old job data to cold storage

**Queue Scaling:**
- Partition queues by job type/priority
- Use Kafka for high-throughput scenarios (millions of jobs/day)

**Caching Strategy:**
- Cache frequently accessed job statuses
- Implement cache-aside pattern
- Use Redis Cluster for distributed caching

---

## 2. Database Design & Data Flow

### Database Selection Strategy

| Data Type | Storage | Rationale |
|-----------|---------|-----------|
| **Job Metadata** | PostgreSQL | Structured data, ACID compliance, complex queries |
| **Job Status (Real-time)** | Redis | Fast read/write, TTL support, pub/sub for updates |
| **Job Execution Logs** | PostgreSQL / File Storage | Searchable logs, long-term retention |
| **User Information** | PostgreSQL | Relational data, authentication |
| **Distributed Locks** | Redis | Atomic operations, TTL-based expiry |
| **Job Queue** | RabbitMQ/Kafka | Message durability, ordering guarantees |

### PostgreSQL Schema

**Users Table**
```sql
users (
  id: UUID PRIMARY KEY,
  email: VARCHAR UNIQUE,
  name: VARCHAR,
  created_at: TIMESTAMP,
  updated_at: TIMESTAMP
)
```

**Jobs Table**
```sql
jobs (
  id: UUID PRIMARY KEY,
  user_id: UUID FOREIGN KEY,
  job_type: VARCHAR,
  payload: JSONB,
  schedule_type: ENUM('one_time', 'recurring'),
  cron_expression: VARCHAR (for recurring),
  scheduled_at: TIMESTAMP,
  status: ENUM('pending', 'queued', 'running', 'completed', 'failed', 'cancelled'),
  retry_count: INTEGER DEFAULT 0,
  max_retries: INTEGER DEFAULT 3,
  created_at: TIMESTAMP,
  updated_at: TIMESTAMP,
  INDEX(user_id, status),
  INDEX(scheduled_at, status)
)
```

**Job Executions Table**
```sql
job_executions (
  id: UUID PRIMARY KEY,
  job_id: UUID FOREIGN KEY,
  started_at: TIMESTAMP,
  completed_at: TIMESTAMP,
  status: ENUM('success', 'failed'),
  error_message: TEXT,
  execution_time_ms: INTEGER,
  INDEX(job_id, started_at)
)
```

### Redis Data Structures

```
# Job Status Cache (Hash)
job:status:{job_id} -> {status, updated_at, progress}
TTL: 24 hours

# Distributed Lock (String)
lock:scheduler:{job_id} -> worker_id
TTL: 30 seconds

# Rate Limiting (String)
ratelimit:user:{user_id} -> request_count
TTL: 1 minute

# Job Queue Metadata (Sorted Set)
pending_jobs -> {job_id: scheduled_timestamp}
```

### Data Flow

**Job Submission Flow:**
1. Client → API Gateway → Job Service
2. Job Service validates & stores in PostgreSQL
3. Job Service caches status in Redis
4. Returns job_id to client

**Job Execution Flow:**
1. Scheduler polls PostgreSQL for due jobs
2. Acquires Redis lock for each job
3. Pushes job to Message Queue
4. Worker picks job from queue
5. Updates status in Redis (real-time)
6. Executes job logic
7. Updates PostgreSQL with execution result
8. Releases lock

**Recurring Job Flow:**
1. After execution, Scheduler calculates next run time
2. Updates `scheduled_at` in PostgreSQL
3. Job remains in system for next execution

---

## 3. API Endpoints

### 1. **POST /api/v1/jobs**
**Description**: Submit a new job  
**Request Body**:
```json
{
  "job_type": "email_notification",
  "payload": {...},
  "schedule_type": "one_time",
  "scheduled_at": "2025-11-10T10:00:00Z",
  "max_retries": 3
}
```
**Response**: `201 Created` with job_id

---

### 2. **POST /api/v1/jobs/recurring**
**Description**: Submit a recurring job  
**Request Body**:
```json
{
  "job_type": "data_backup",
  "payload": {...},
  "cron_expression": "0 0 * * *",
  "max_retries": 3
}
```
**Response**: `201 Created` with job_id

---

### 3. **GET /api/v1/jobs/{job_id}**
**Description**: Get job details and status  
**Response**: 
```json
{
  "job_id": "uuid",
  "status": "completed",
  "scheduled_at": "...",
  "created_at": "...",
  "executions": [...]
}
```

---

### 4. **GET /api/v1/jobs**
**Description**: List all jobs for authenticated user  
**Query Params**: `status`, `page`, `limit`, `sort_by`  
**Response**: Paginated list of jobs

---

### 5. **PUT /api/v1/jobs/{job_id}/reschedule**
**Description**: Reschedule a pending job  
**Request Body**:
```json
{
  "scheduled_at": "2025-11-11T10:00:00Z"
}
```
**Response**: `200 OK` with updated job

---

### 6. **DELETE /api/v1/jobs/{job_id}**
**Description**: Cancel a pending/scheduled job  
**Response**: `204 No Content`

---

### 7. **GET /api/v1/jobs/{job_id}/executions**
**Description**: Get execution history for a job  
**Response**: List of execution records with timestamps, status, errors

---

### 8. **GET /api/v1/health**
**Description**: System health check  
**Response**: 
```json
{
  "status": "healthy",
  "services": {
    "database": "up",
    "redis": "up",
    "queue": "up"
  },
  "metrics": {
    "pending_jobs": 150,
    "active_workers": 10
  }
}
```

---

## Summary

This HLD provides a scalable, fault-tolerant job scheduling system with:
- **Distributed architecture** supporting horizontal scaling
- **Hybrid storage strategy** (PostgreSQL + Redis) for optimal performance
- **Message queue** for reliable job execution
- **Comprehensive APIs** for job lifecycle management
- **Built-in monitoring** and failure handling mechanisms

The system can handle thousands of concurrent jobs and scale to millions with proper infrastructure provisioning.
