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
