#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left= NULL;
        right= NULL;
    }
};

bool getPath(Node *root, int key, vector<int> &path){
    if(root == NULL)
    return false;

    path.push_back(root->data);  // for checking ultimately that root data equals to key or not
    if(root->data==key){
        return true;
    }
    if(getPath(root->left, key, path) || getPath(root->right,key,path)){ // if root data not equals to key, then check left subtree and right subtree
        return true;
    }
    path.pop_back();
    return false;

}


int LCA(Node* root, int n1, int n2){
    vector<int> path1,path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){  //  checking path from root to node exists or not
        return -1;
    }
    int pathchange;
    for(pathchange = 0;pathchange<min(path1.size(), path2.size());pathchange++){
        if(path1[pathchange] != path2[pathchange]){
            break;
        }
    }
    return path1[pathchange-1];
}

int main(){
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

    int n1=1;
    int n2=8;
    int lca=LCA(root, n1, n2);
    if(lca==-1)
    cout<<"LCA not exist.\n";
    else{
        cout<<lca<<endl;
    }


}
