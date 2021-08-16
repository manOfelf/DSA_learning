#include <bits/stdc++.h>
using namespace std;
#define COUNT 5

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

int transform(Node *root)
{
    if (!root)
        return 0;

    int lsum = transform(root->left);
    int rsum = transform(root->right);
    int val = lsum + rsum + root->data;

    root->data = lsum + rsum;

    return val;
}

void print2DUtil(Node *root, int space)
{
    // Base case
    if (root == NULL)
        return;
    // Increase distance between levels
    space += COUNT;
    // Process right child first
    print2DUtil(root->right, space);
    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";
    // Process left child
    print2DUtil(root->left, space);
}
// Wrapper over print2DUtil()
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main()
{
    /*
             20
           /   \
         -2     6
         / \   / \
        8  -4 7   5
*/
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->right = new Node(5);
    root->right->left = new Node(7);

    transform(root);
    print2D(root);
}
