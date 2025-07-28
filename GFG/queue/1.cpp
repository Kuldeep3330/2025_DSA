#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int size, cap, front;
    int *arr;
    Queue(int c)
    {
        cap = c;
        size = 0;
        arr = new int[cap];
        front = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }
    void push(int x)
    {
        if (size == cap)
        {
            cout << "overflow\n";
            return;
        }
        int rear = (front + size) % cap;
        arr[rear] = x;
        size++;
    }
    int pop()
    {
        if (size == 0)
        {
            cout << "underflow\n";
            return INT_MIN;
        }
        int res = arr[front];
        front = (front + 1) % cap;
        size--;
        return res;
    }
    int getFront()
    {
        if (size == 0)
            return -1;
        return arr[front];
    }
    int getRear()
    {
        if (size == 0)
            return -1;
        return arr[(front + size - 1) % cap];
    }
    bool isFull()
    {
        return (size == cap);
    }
    bool isEmpty()
    {
        return (size == 0);
    }
};

int main()
{
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    q.pop();
    cout << "Front after pop: " << q.getFront() << endl;
    return 0;
}
