#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

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
void swap(Node *&root1, Node *&root2)
{
    Node *temp = root1;
    root1 = root2;
    root2 = temp;
}
void Invert(Node *&root)
{
    if (!root)
        return;
    Node *temp = root->left;
    swap(root->right, root->left);
    Invert(root->right);
    Invert(root->left);
}
/* 

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
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
    // Process left child
    print2DUtil(root->left, space);
}
// Wrapper over print2DUtil()
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
*/
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
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    root->left->right->left = new Node(7);
    root->left->right->left->left = new Node(9);
    root->left->right->left->left->left = new Node(10);

    Invert(root);

    // print2D(root);
}
