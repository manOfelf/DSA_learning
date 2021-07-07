#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void LevelOrder(Node *root, stack<int> &vec)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        vec.push(temp->data);

        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }
}

int main()
{

    struct Node *
        root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
           
          
*/

    stack<int> vec;

    LevelOrder(root, vec);

    while (!vec.empty())
    {
        int temp = vec.top();
        vec.pop();
        cout << temp << " ";
        //  4 5 6 7 2 3 1
    }
}
