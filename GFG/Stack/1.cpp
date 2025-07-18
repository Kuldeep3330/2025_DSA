#include <bits/stdc++.h>

using namespace std;

// method I
//  struct MyStack
//  {
//      int *arr;
//      int cap;
//      int top;
//      MyStack(int n)
//      {
//          cap = n;
//          arr = new int[cap];
//          top = -1;
//      }
//      void push(int x)
//      {
//          top++;
//          arr[top] = x;
//      }
//      int pop()
//      {
//          int res = arr[top];
//          top--;
//          return res;
//      }
//      int peek()
//      {
//          return arr[top];
//      }
//      int size()
//      {
//          return (top + 1);
//      }
//      bool isEmpty()
//      {
//          return (top == -1);
//      }
//  };

// using vector
// struct MyStack
// {
//     vector<int> v;
//     void push(int x)
//     {
//         v.push_back(x);
//     }
//     int pop()
//     {
//         int res = v.back();
//         v.pop_back();
//         return res;
//     }
//     int size()
//     {
//         return v.size();
//     }
//     bool isEmpty()
//     {
//         return v.empty();
//     }

//     int peek()
//     {
//         return v.back();
//     }
// };

// Linked List implementation
struct Node
{
    Node *next;
    int data;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct MyStack
{
    Node *head;
    int sz;
    MyStack()
    {
        head = NULL;
        sz = 0;
    }
    void push(int x)
    {
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        sz++;
    }
    int pop()
    {
        if (head == NULL)
            return INT_MAX;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete (temp);
        sz--;
        return res;
    }
    int peek()
    {
        if (head == NULL)
            return INT_MAX;
        return head->data;
    }
};
int main()
{
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(30);
    cout << s.peek() << "\t";
    cout << s.pop() << "\t";

    return 0;
}