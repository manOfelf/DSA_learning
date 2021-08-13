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

int main()
{
    /*
            1
           / \
          2   3
         / \   
        4   5   
*/
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
/*
            1
           / \
          3   2
             / \   
            5   4 
*/
    Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->right->right = new Node(4);
    root2->right->left = new Node(5);

    bool check = isMirrorOfTree(root1, root2);
    if (check)
        cout << "Yes\n";
    else
        cout << "No\n";
}
