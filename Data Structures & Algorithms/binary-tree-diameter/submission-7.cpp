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

        //store maximum depth we have seen so far in res
        depth(root);
        return res;
    }

    int depth(TreeNode *node)
    {
        if(!node)
        return 0;

        int leftDepth = depth(node -> left);
        int rightDepth = depth(node -> right);

        res = max(res, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }
};
