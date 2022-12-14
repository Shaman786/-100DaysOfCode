#include<bits/stdc++.h>

class Node{
    public:
    int data;
    Node *next;
};

void push(Node** head_ref, int new_data){

    //1. allocate node
    Node* new_node = new Node();

    //2. put in the data
    new_data->data = new_data;

    //3. Make next of new node as head
    new_node->next = (*head_ref);

    //4. Move the head to point to
    //the new Node
    (*head_ref) = new_node;
}