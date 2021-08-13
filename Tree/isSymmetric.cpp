#include <bits/stdc++.h>
using namespace std;

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

bool isMirrorOfTree(Node *root1, Node *root2)
{
    if (!root1 and !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->data != root2->data)
        return false;

    return isMirrorOfTree(root1->left, root2->right) and
           isMirrorOfTree(root1->right, root2->left);

    return false;
}
bool isSymmetry(Node *root)
{
    if (!root)
        return true;

    return isMirrorOfTree(root->left, root->right);
}
int main()
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
           /
          7
         /
        9
       /
     10
*/
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(3);
    //root->left->left = new Node(4);
    // root->left->right = new Node(5);
    //root->right->right = new Node(4);
    // root->left->right->left = new Node(7);
    // root->left->right->left->left = new Node(9);
    // root->left->right->left->left->left = new Node(10);

    if (isSymmetry(root))
        cout << "Yes\n";
    else
        cout << "No\n";
}
