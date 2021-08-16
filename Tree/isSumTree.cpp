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

int SumTree(Node *root, bool &flag)
{
    if (!root)
        return 0;
    if (!root->left and !root->right)
        return root->data;

    int lsum = SumTree(root->left, flag);
    int rsum = SumTree(root->right, flag);
    if (root->data != lsum + rsum)
        flag = false;

    return root->data + lsum + rsum;
}
bool isSumTree(Node *root)
{
    bool flag = true;
    cout << SumTree(root, flag) << endl;

    return flag;
}
int main()
{
    /*
            20
           /  \
          4    6
         / \    \
        4   0    6
*/
    Node *root = new Node(20);
    root->left = new Node(4);
    root->right = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(0);
    root->right->right = new Node(6);

    if (isSumTree(root))
        cout << "Yes\n";
    else
        cout << "No\n";
}
