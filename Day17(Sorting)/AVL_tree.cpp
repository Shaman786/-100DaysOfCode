// AVL tree implementation in C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b);

// Calculate height
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

// New node creation
Node *newNode(int key)
{
    Node *node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// Rotate right
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    return x;
}

// Rotate left
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left),
                    height(x->right)) +
                1;
    y->height = max(height(y->left),
                    height(y->right)) +
                1;
    return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int key)
{
    // Find the correct postion and insert the node
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    // Update the balance factor of each node and
    // balance the tree
    node->height = 1 + max(height(node->left),
                           height(node->right));
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1)
    {
        if (key < node->left->key)
        {
            return rightRotate(node);
        }
        else if (key > node->left->key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balanceFactor < -1)
    {
        if (key > node->right->key)
        {
            return leftRotate(node);
        }
        else if (key < node->right->key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
    return node;
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node)
{
    Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node
Node *deleteNode(Node *root, int key)
{
    // Find the node and delete it
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = nodeWithMimumValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,
                                     temp->key);
        }
    }

    if (root == NULL)
        return root;

    // Update the balance factor of each node and
    // balance the tree
    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balanceFactor = getBalanceFactor(root);
    if (balanceFactor > 1)
    {
        if (getBalanceFactor(root->left) >= 0)
        {
            return rightRotate(root);
        }
        else
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balanceFactor < -1)
    {
        if (getBalanceFactor(root->right) <= 0)
        {
            return leftRotate(root);
        }
        else
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }
    return root;
}
// insert a node

// Print the tree
void printTree(Node *root, string indent, bool last)
{
    if (root != nullptr)
    {
        cout << indent;
        if (last)
        {
            cout << "R----";
            indent += "   ";
        }
        else
        {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->key << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}

int main()
{
    cout << "Enter the number of nodes in the tree: ";
    int n;
    cin >> n;
    Node *root = NULL;
    cout << "Enter the nodes: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = insertNode(root, x);
    }
    cout << "Tree: " << endl;
    printTree(root, "", true);
    cout << "Choose an option: " << endl;
    cout << "1. Insert a node" << endl;
    cout << "2. Delete a node" << endl;
    cout << "3. Exit" << endl;
    int choice;
    cin >> choice;
    while (choice != 3)
    {
        if (choice == 1)
        {
            cout << "Enter the node to be inserted: ";
            int x;
            cin >> x;
            root = insertNode(root, x);
            cout << "Tree: " << endl;
            printTree(root, "", true);
            // back to menu
            break;
        }
        else if (choice == 2)
        {
            cout << "Enter the node to be deleted: ";
            int x;
            cin >> x;
            root = deleteNode(root, x);
            cout << "Tree: " << endl;
            printTree(root, "", true);
            // back to menu
            break;
        }
        else
        {
            cout << "Invalid choice" << endl;
            break;
        }
    }
}

// psuedo code

// 1. insertNode(node, key)
// 2. if node is null
// 3. return new node
// 4. if key is less than node
// 5. node.left = insertNode(node.left, key)
// 6. else if key is greater than node
// 7. node.right = insertNode(node.right, key)
// 8. else
// 9. return node
// 10. node.height = 1 + max(height(node.left), height(node.right))
// 11. balanceFactor = getBalanceFactor(node)
// 12. if balanceFactor > 1
// 13. if key < node.left.key
// 14. return rightRotate(node)
// 15. else if key > node.left.key
// 16. node.left = leftRotate(node.left)
// 17. return rightRotate(node)
// 18. if balanceFactor < -1
// 19. if key > node.right.key
// 20. return leftRotate(node)
// 21. else if key < node.right.key
// 22. node.right = rightRotate(node.right)
// 23. return leftRotate(node)
// 24. return node

// 1. deleteNode(node, key)
// 2. if node is null
// 3. return node
// 4. if key is less than node
// 5. node.left = deleteNode(node.left, key)
// 6. else if key is greater than node
// 7. node.right = deleteNode(node.right, key)
// 8. else
// 9. if node.left is null or node.right is null
// 10. temp = node.left ? node.left : node.right
// 11. if temp is null
// 12. temp = node
// 13. node = null
// 14. else
// 15. node = temp
// 16. free(temp)
// 17. else
// 18. temp = nodeWithMimumValue(node.right)
// 19. node.key = temp.key
// 20. node.right = deleteNode(node.right, temp.key)
// 21. if node is null
// 22. return node
// 23. node.height = 1 + max(height(node.left), height(node.right))
// 24. balanceFactor = getBalanceFactor(node)
// 25. if balanceFactor > 1
// 26. if getBalanceFactor(node.left) >= 0
// 27. return rightRotate(node)
// 28. else
// 29. node.left = leftRotate(node.left)
// 30. return rightRotate(node)
// 31. if balanceFactor < -1
// 32. if getBalanceFactor(node.right) <= 0
// 33. return leftRotate(node)
// 34. else
// 35. node.right = rightRotate(node.right)
// 36. return leftRotate(node)
// 37. return node

// 1. insertNode(node, key)
// 2. check if node is null
// 3. if node is null
// 4. return new node
// 5. if key is less than node
// 6. left node is inserted in the left subtree
// 7. else if key is greater than node
// 8. right node is inserted in the right subtree
// 9. return node
// 10. height of the node is updated
// 11. balanceFactor is calculated using the height of the left and right subtree
// 12. balanceFactor > 1 means the tree is left heavy
// 13. key < node.left.key means the left subtree is left heavy
// 14. return rightRotate(node)
// 15. else key > node.left.key means the left subtree is right heavy
// 16. left node is inserted in the left subtree
// 17. return rightRotate(node)
// 18. balanceFactor < -1 means the tree is right heavy
// 19. key > node.right.key means the right subtree is right heavy
// 20. return leftRotate(node)
// 21. else key < node.right.key means the right subtree is left heavy
// 22. right node is inserted in the right subtree
// 23. return leftRotate(node)
// 24. return node

// 1. deleteNode(node, key)
// 2. check if node is null
// 3. if node is null
// 4. return node
// 5. if key is less than node
// 6. left node is deleted in the left subtree
// 7. else if key is greater than node
// 8. right node is deleted in the right subtree
// 9. else if left node is null or right node is null
// 10 temp is assigned to the left node if it is not null else right node
// 11. if temp is null
// 12. temp is assigned to the node
// 13. node is assigned to null
// 14. else node is assigned to temp
// 15. free(temp)
// 16. else temp is assigned to the node with minimum value in the right subtree
// 17. node is assigned to temp
// 18. right node is deleted in the right subtree
// 19. if node is null
// 20. return node
// 21. height of the node is updated
// 22. balanceFactor is calculated using the height of the left and right subtree
// 23. balanceFactor > 1 means the tree is left heavy
// 24. getBalanceFactor(node.left) >= 0 means the left subtree is left heavy
// 25. return rightRotate(node)
// 26. else getBalanceFactor(node.left) < 0 means the left subtree is right heavy
// 27. left node is deleted in the left subtree
// 28. return rightRotate(node)
// 29. balanceFactor < -1 means the tree is right heavy
// 30. getBalanceFactor(node.right) <= 0 means the right subtree is right heavy
// 31. return leftRotate(node)
// 32. else getBalanceFactor(node.right) > 0 means the right subtree is left heavy
// 33. right node is deleted in the right subtree
// 34. return leftRotate(node)
// 35. return node
