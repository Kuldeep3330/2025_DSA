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

Node *sortedInsert(Node *head, int x)
{
    Node *temp = new Node(x);
    Node *curr = head;
    while (curr->next->data < x)
    {

        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// middle of the linked list
int middleOfLL(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
// find nth node from end of Linked List
int nthFromEnd(Node *head, int n)
{
    Node *fast = head;
    while (n != 0)
    {
        fast = fast->next;
        n--;
    }
    Node *slow = head;
    while (fast != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

// reverse the LInked List
Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void removeDups(Node *head)
{
    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete (temp);
        }
        else
        {
            curr = curr->next;
        }
    }
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(30);
    head->next->next = new Node(50);
    head->next->next->next = new Node(70);
    head = sortedInsert(head, 35);
    head = reverseLL(head);
    // cout << nthFromEnd(head, 2) << "\t";

    // cout << middleOfLL(head) << endl;
    // head = insertAtGvnPos(head, 5, 20);
    // head = deleteFirst(head);
    // head = insertAtBeg(head, 5);
    // head = insertAtEnd(head, 40);

    traverse(head);

    return 0;
}