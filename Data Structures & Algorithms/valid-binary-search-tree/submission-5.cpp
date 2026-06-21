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
       return check(root, LONG_MIN, LONG_MAX);
    }

    bool check(TreeNode* node, long long min_val, long long max_val)
    {
        if(!node)
        return true;
        
        if(node -> val > min_val && node -> val < max_val)
        {
            //this node is valid
            return check(node -> left, min_val, node -> val) && check(node -> right, node ->val, max_val);
        
        }
        else
        return false;
    }
};
