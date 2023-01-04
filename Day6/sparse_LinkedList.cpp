/*  In linked list, each node has four fields. These four fields are defined as:

Row: Index of row, where non-zero element is located
Column: Index of column, where non-zero element is located
Value: Value of the non zero element located at index – (row,column)
Next node: Address of the next node
*/

// link to the actual code https://www.geeksforgeeks.org/sparse-matrix-representation/

// C++ program for sparse matrix representation.
// Using Link list

#include <iostream>
using namespace std;

// Node class to represent link list
class Node
{
public:
    int row;
    int col;
    int data;
    int n;

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

// Driver Code
int main()
{

    // 4x5 sparse matrix
    int sparseMatrix[4][5] = {{0, 0, 3, 0, 4},
                              {0, 0, 5, 7, 0},
                              {0, 0, 0, 0, 0},
                              {0, 2, 6, 0, 0}};
    int n;
    cin >> n;

    // Creating head/first node of list as NULL
    Node *first = NULL;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            // Pass only those values which
            // are non - zero
            if (sparseMatrix[i][j] != 0)
                create_new_node(&first, i, j,
                                sparseMatrix[i][j]);
        }
    }
    printList(first);

    return 0;
}

/*Output
row_position:0 0 1 1 3 3
column_position:2 4 2 3 1 2
Value:3 4 5 7 2 6  */