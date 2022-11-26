// Implementation of Tree Traversals [Inorder, Preorder, Postorder]

#include <bits/stdc++.h>
using namespace std;

// create a node
struct node
{
    int item;
    struct node *left;
    struct node *right;
};

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->item << " ";
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->item << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->item << " ";
}

// create a new node
struct node *newNode(int item)
{
    struct node *temp = new node;
    temp->item = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node *insertLeft(struct node *root, int item)
{
    root->left = newNode(item);
    return root->left;
}

struct node *insertRight(struct node *root, int item)
{
    root->right = newNode(item);
    return root->right;
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int arr[n];
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    struct node *root = newNode(arr[0]);
    struct node *temp = root;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            temp = insertLeft(temp, arr[i]);
        }
        else
        {
            temp = insertRight(temp, arr[i]);
        }
    }
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
    return 0;
}

// pseudocode

// 1. function inorder(node)
// 2.     if node = null then return
// 3.     inorder(node.left)
// 4.     visit(node)
// 5.     inorder(node.right)
// 6. function preorder(node)
// 7.     if node = null then return
// 8.     visit(node)
// 9.     preorder(node.left)
// 10.     preorder(node.right)
// 11. function postorder(node)
// 12.     if node = null then return
// 13.     postorder(node.left)
// 14.     postorder(node.right)
// 15.     visit(node)

// explanation
// 1. function inorder(node)
// 2. check if the node is null
// 3. if not null, then traverse the left subtree
// 4. visit the node
// 5. traverse the right subtree
// 6. function preorder(node)
// 7. check if the node is null
// 8. if not null, then visit the node
// 9. traverse the left subtree
// 10. traverse the right subtree
// 11. function postorder(node)
// 12. check if the node is null
// 13. traverse the left subtree
// 14. traverse the right subtree
// 15. visit the node

// output:
//  Enter the number of nodes: 7
//  Enter the values of the nodes: 1 2 3 4 5 6 7
//  Inorder traversal: 4 2 5 1 6 3 7
//  Preorder traversal: 1 2 4 5 3 6 7
//  Postorder traversal: 4 5 2 6 7 3 1

// output:
//  Enter the number of nodes: 5
//  Enter the values of the nodes: 1 2 3 4 5
//  Inorder traversal: 2 1 4 3 5
//  Preorder traversal: 1 2 3 4 5
//  Postorder traversal: 2 4 5 3 1

// output:
//  Enter the number of nodes: 4
//  Enter the values of the nodes: 12 32 59 22
//  Inorder traversal: 32 12 59 22
//  Preorder traversal: 12 32 59 22
//  Postorder traversal: 32 59 22 12

// Incorrect output:
//  Enter the number of nodes: 5
//  Enter the values of the nodes: 1 2 3 4 5
//  Inorder traversal: 2 1 4 3 5
//  Preorder traversal: 1 2 3 4 5
//  Postorder traversal: 2 4 5 3 1
