/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    int count = 0;

    int goodNodes(TreeNode* root) 
    {
        dfs(root, root -> val);
        return count;
    }

    void dfs (TreeNode* node, int maxval)
    {
        if(!node)
        return;

        if(node -> val >= maxval)
        {
            count++;
            maxval = node -> val;
        }

        dfs(node -> left, maxval);
        dfs(node -> right, maxval);
        
    }
};
