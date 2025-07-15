#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void traverse(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
// insert at begin
Node *insertAtBeg(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}

// insert at the end
Node *insertAtEnd(Node *head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
        return temp;
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

// insert at given position in singly Linked List
Node *insertAtGvnPos(Node *head, int pos, int x)
{
    Node *temp = new Node(x);
    if (pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for (int i = 0; i < pos - 2 && curr != NULL; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// Delete first node in singly linked list
Node *deleteFirst(Node *head)
{
    Node *temp = head->next;
    delete head;
    return temp;
}

// delete last node in singly linked list
Node *deleteLast(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *curr = head;
    while (curr->next->next != NULL)
    {
        curr = curr->next;
    }
    delete (curr->next);
    curr->next = NULL;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(50);
    head->next->next->next = new Node(70);
    head = insertAtGvnPos(head, 5, 20);
    head = deleteFirst(head);
    // head = insertAtBeg(head, 5);
    // head = insertAtEnd(head, 40);
    traverse(head);

    return 0;
}