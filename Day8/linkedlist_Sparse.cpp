// C++ program for sparse matrix representation.
// Using Link list
#include <bits/stdc++.h>
using namespace std;

// Node class to represent link list
class Node
{
public:
    int row;
    int col;
    int data;
    Node *next;
};

// Function to create new node
void create_new_node(Node **p, int row_index,
                     int col_index, int x)
{
    Node *temp = *p;
    Node *r;

    // If link list is empty then
    // create first node and assign value.
    if (temp == NULL)
    {
        temp = new Node();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }

    // If link list is already created
    // then append newly created node
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        r = new Node();
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}

// Function prints contents of linked list
// starting from start
void printList(Node *start)
{
    Node *ptr = start;
    cout << "row_position:";
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "column_position:";

    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->col << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Value:";
    ptr = start;

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
void deleteNode(Node **head_ref, int key)
{
    // Store head node
    Node *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    delete temp;
}
void search(Node *start, int key)
{
    Node *ptr = start;
    int flag = 0;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            cout << "Element found at row " << ptr->row << " and column " << ptr->col << endl;
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (flag == 0)
        cout << "Element not found" << endl;
}

void insert_element(Node **start)
{
    int row, col, x;
    cout << "Enter row and column of element to be inserted\n";
    cin >> row >> col;
    cout << "Enter element to be inserted\n";
    cin >> x;
    create_new_node(start, row, col, x);
    cout << "The new sparse matrix is\n";
    printList(*start);
}
// Driver Code
int main()
{

    cout << "Enter the order of matrix" << endl;
    int row, col;
    cin >> row >> col;
    int a[row][col];
    cout << "Enter the elements of matrix" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "The matrix is" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    Node *start = NULL;
    cout << "The sparse matrix is" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (a[i][j] != 0)
            {
                create_new_node(&start, i, j, a[i][j]);
            }
        }
    }
    printList(start);
    int choice;
    cout << "\nEnter 1 to insert element, 2 to delete element, 3 to search element, 4 to exit" << endl;
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            insert_element(&start);
            break;
        case 2:
            int key;
            cout << "Enter the element to be deleted" << endl;
            cin >> key;
            deleteNode(&start, key);
            cout << "The new sparse matrix is\n";
            printList(start);
            break;
        case 3:
            int key1;
            cout << "Enter the element to be searched" << endl;
            cin >> key1;
            search(start, key1);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
        cout << "\nEnter 1 to insert element, 2 to delete element, 3 to search element, 4 to exit" << endl;
        cin >> choice;
    }

    return 0;
}
