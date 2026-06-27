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
    bool isValidBST(TreeNode* root) 
    {

        return dfs(root, LONG_MAX, LONG_MIN);
        
    }

    bool dfs(TreeNode* node, long long maxv, long long minv)
    {
        if(!node)
        return true;

        if(node -> val < maxv && node -> val > minv)
        {
            return dfs(node -> left, node -> val, minv) && dfs(node -> right, maxv, node -> val);
        }
        else
        return false;
    }
};
