#include<iostream>
#include<queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    bool isEmpty() {
        return q1.empty() && q2.empty();
    }

    void push(int x) {
        if (!q1.empty()) {
            q1.push(x);
        } else {
            q2.push(x);
        }
    }

    int pop() {
        if (isEmpty())
            return -1;

        int res = -1;
        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            res = q1.front();
            q1.pop();
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            res = q2.front();
            q2.pop();
        }
        return res;
    }

    int top() {
        if (isEmpty())
            return -1;

        int res = -1;
        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            res = q1.front();
            q2.push(res); // Don't discard it
            q1.pop();
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            res = q2.front();
            q1.push(res); // Don't discard it
            q2.pop();
        }
        return res;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl; // 30
    cout << s.pop() << endl; // 30
    cout << s.top() << endl; // 20
    cout << s.pop() << endl; // 20
    cout << s.pop() << endl; // 10
    cout << s.pop() << endl; // -1 (empty)

    return 0;
}
