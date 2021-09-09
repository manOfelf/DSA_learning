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

Node *LCA(Node *root, int n1, int n2)
{
    if (!root)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);
    if (left && right)
        return root;
    if (left)
        return left;
    if (right)
        return right;

    return NULL;
}
int dist(Node *root, int n, int lvl)
{
    if (root == NULL)
        return -1;
    if (root->data == n)
        return lvl;

    int l = dist(root->left, n, lvl + 1);
    if (l == -1)
        return dist(root->right, n, lvl + 1);
    return l;
}
int DistanceBetween2Nodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);
    //cout<<lca->data<<endl;
    if (!lca)
        return -1;

    int distance = dist(lca, n1, 0) + dist(lca, n2, 0);
    return distance;
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

    int n1 = 1;
    int n2 = 6;

    cout << DistanceBetween2Nodes(root, n1, n2) << endl;
}
