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
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
        return true;

        int left = dfs(root -> left);
        int right = dfs(root -> right);


        if(abs(left-right) > 1)
        return false;
        else
        return isBalanced(root->left) && isBalanced(root-> right);
    }

    int dfs(TreeNode* node)
    {
        if(!node)
        return 0;

        return 1 + max(dfs(node->left), dfs(node-> right));
    }
};
