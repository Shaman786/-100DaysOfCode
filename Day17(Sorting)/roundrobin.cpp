// implement circular doubly linked list in round robin scheduling algorithm

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class CircularDoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    CircularDoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = head;
            head->prev = tail;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp->next != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
    void deleteNode(int data)
    {
        Node *temp = head;
        while (temp->data != data)
        {
            temp = temp->next;
        }
        if (temp == head)
        {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        else if (temp == tail)
        {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
};

int main()
{
    CircularDoublyLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.insert(40);
    cll.insert(50);
    cll.display();
    cll.deleteNode(30);
    cll.display();
    return 0;
}

// Output: 10 20 30 40 50 10 20 40 50
