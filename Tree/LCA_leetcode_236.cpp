/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool getPath(TreeNode *root, int key, vector<TreeNode *> &path)
    {
        if (!root)
            return false;
        path.push_back(root);
        if (root->val == key)
            return true;
        if (getPath(root->left, key, path) || getPath(root->right, key, path))
        {
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path1, path2;

        if (!getPath(root, p->val, path1) || !getPath(root, q->val, path2))
            return NULL;
        int pathchange;
        for (pathchange = 0; pathchange <= min(path1.size(), path2.size()); pathchange++)
            if (path1[pathchange] != path2[pathchange])
                break;

        return path1[pathchange - 1];
    }
};
