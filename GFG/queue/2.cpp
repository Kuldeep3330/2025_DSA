#include<iostream>
#include<stack>
using namespace std;
class Queue {
    stack<int> s1, s2;
public:
    void enqueue(int x) {
        s1.push(x);
    }
    int dequeue() {        
        if(isEmpty()){
            return -1;
        }else if(!s2.empty()){
            int top = s2.top();
            s2.pop();
            return top;
        }else{
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }        
    }
    int front() {
        if (isEmpty()) {
            return -1;
        }else if(!s2.empty()){
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};
