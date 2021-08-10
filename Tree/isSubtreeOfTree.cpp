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

bool isIdentical(Node *root1, Node *root2)
{
    if (!root1 and !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->data != root2->data)
        return false;
    
    bool l=isIdentical(root1->left, root2->left);
    bool r=isIdentical(root1->right, root2->right);
    if(l and r)
    return true;
    else
    return false;
}
bool isSubtree(Node *root1, Node* root2)
{
    if(!root1 and !root2)
    return true;

    if(!root1 || !root2)
    return false;

    if(isIdentical(root1,root2))
    return true;

    return (isSubtree(root1->left,root2) || isSubtree(root1->right,root2));
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
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->right->left = new Node(5);
    root1->right->right = new Node(6);
    root1->right->left->left = new Node(7);
    /*
            
            3
           / \
          5   6
         /
        7
*/
    Node *root2 = new Node(3);
    root2->left = new Node(5);
    root2->right = new Node(6);
    root2->left->left = new Node(7);
    

    if (isSubtree(root1, root2))
        cout << "True\n";
    else
        cout << "False\n";
}
