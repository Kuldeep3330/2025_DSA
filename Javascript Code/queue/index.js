// class MyQueue {
//     constructor() {
//         this.arr = [];
//     }

//     // Enqueue - Add item at the end of the queue
//     enqueue(x) {
//         this.arr.push(x);
//     } 

//     // Dequeue - Remove item from the front of the queue
//     dequeue() {
//         if (this.isEmpty()) {
//             throw new Error("Underflow");
//         }
//         return this.arr.shift();
//     }

//     // Get the item at the front of the queue
//     front() {
//         if (this.isEmpty()) {
//             throw new Error("Queue is empty");
//         }
//         return this.arr[0];
//     }

//     // Check if the queue is empty
//     isEmpty() {
//         return this.arr.length === 0;
//     }

//     // Get the size of the queue
//     size() {
//         return this.arr.length;
//     }
// }
// const q = new MyQueue();
// q.enqueue(10);
// q.enqueue(20);
// q.enqueue(30);
// console.log(q.dequeue()); // 10
// console.log(q.front());   // 20
// console.log(q.size());    // 2

//linked implementation of Queue
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class MyQueue {
    constructor() {
        this.head = null; // Front of the queue
        this.tail = null; // Rear of the queue
        this.sz = 0;
    }

    enqueue(x) {
        const temp = new Node(x);
        if (this.tail === null) {
            // Queue is empty
            this.head = this.tail = temp;
        } else {
            this.tail.next = temp;
            this.tail = temp;
        }
        this.sz++;
    }

    dequeue() {
        if (this.isEmpty()) {
            throw new Error("Queue underflow");
        }
        const value = this.head.data;
        this.head = this.head.next;
        if (this.head === null) {
            this.tail = null; // Queue is now empty
        }
        this.sz--;
        return value;
    }

    front() {
        if (this.isEmpty()) {
            throw new Error("Queue is empty");
        }
        return this.head.data;
    }

    size() {
        return this.sz;
    }

    isEmpty() {
        return this.sz === 0;
    }
}


const q = new MyQueue();
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
console.log(q.dequeue()); // 1
console.log(q.front());   // 2
console.log(q.size());    // 2
console.log(q.isEmpty()); // false

