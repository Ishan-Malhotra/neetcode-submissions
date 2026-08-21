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
        return dfs(root, INT_MAX, INT_MIN);
        
    }

    bool dfs(TreeNode* node, int maxi, int mini)
    {
        if(!node)
        return true;

        if(node -> val < maxi && node -> val > mini)
        {
            return dfs(node -> left, node -> val, mini) && dfs(node -> right, maxi, node-> val);
        }
        else
        {
            return false;
        }
    }

};
