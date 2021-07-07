#include <bits/stdc++.h>
using namespace std;

// T.C. : O(N)
struct Node
{
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// check for BST
bool isBST(Node *root, Node *min, Node *max)
{
    if (root == NULL)
    {
        return true;
    }
    if (min != NULL and root->data <= min->data)
    {
        return false;
    }
    if (max != NULL and root->data >= max->data)
    {
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);
    return leftValid and rightValid;
}

int main()
{
    /*
            1
           / \
          2   3
         /   / \
        4   5   6
           /
          7
*/
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    if (isBST(root, NULL, NULL))
    {
        cout << "BST" << endl;
    }
    else
    {
        cout << "Not BST" << endl;
    }
}
