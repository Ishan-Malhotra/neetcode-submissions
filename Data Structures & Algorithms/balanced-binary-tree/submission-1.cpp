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
        return dfs(root)[0]; 
    }

    private:
    vector <int> dfs(TreeNode* root)
    {

        //vector[0] = 1 if balanced, 0 if broken
        //vector[1] = height of the subtree

        if (!root)
        return {1,0};
        //[isBalanced, height]

        vector <int> left = dfs(root -> left);
        vector <int> right = dfs(root -> right);

        bool balanced = (left[0] == 1 && right[0] == 1) && (abs(left[1] - right[1]) <= 1);
        int height = 1 + max(left[1] , right[1]);

        return {balanced ? 1 : 0, height};
        
    }
};
