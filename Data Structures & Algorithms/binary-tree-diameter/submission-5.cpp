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

    int res = 0;

    int diameterOfBinaryTree(TreeNode* root) 
    {
    if(!root)
    return 0;

    depth(root);
    return res;

    }

    int depth(TreeNode* node)
    {
        if(!node)
        return 0;

        int left = depth(node -> left);
        int right = depth(node -> right);

        res = max(res, left + right);
        return 1 + max(left, right);
    }
};
