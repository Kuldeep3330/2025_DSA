#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int index;
    Node *next;
    Node(int x)
    {
        index = x;
        next = NULL;
    }
};

struct Kstack
{
    stack<int> st; // to keep track empty index
    int *arr;      // the arr we want to partition into k parts
    Node **top;

    Kstack(int k, int n)
    { // k is number of stacks, n is size of arr
        arr = new int[n];
        top = new Node *[k];
        for (int i = 0; i < k; i++)
        {
            top[i] = NULL;
        }
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }
    }

    void push(int x, int m)
    { // m is kis array me x is kya
        if (st.empty())
        {
            cout << "Overflow\n";
            return;
        }
        arr[st.top()] = x;
        Node *temp = new Node(st.top());
        temp->next = top[m - 1];
        top[m - 1] = temp;
        st.pop();
    }
    int pop(int m)
    {
        if (top[m - 1] == NULL)
        {
            cout << "underflow\n";
            return -1;
        }
        int idx = top[m - 1]->index;
        st.push(idx);
        top[m - 1] = top[m - 1]->next;
        return arr[idx];
    }
};
int main()
{
    return 0;
}