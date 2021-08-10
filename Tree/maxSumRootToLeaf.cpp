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
void Path_Sum(Node *root, int &mxsum, int &sum)
{
    if (root == NULL)
        return;
    sum += root->data;
    if (!root->left && !root->right)
    {
        mxsum = max(sum, mxsum);
    }
    Path_Sum(root->left, mxsum, sum);
    Path_Sum(root->right, mxsum, sum);
    sum -= root->data;
}
int Path(Node *root)
{
    int mxsum = -100000;
    if (!root)
        return mxsum;
    int sum = 0;
    Path_Sum(root, mxsum, sum);

    return mxsum;
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

    cout << Path(root) << endl;
}
