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

    int res = INT_MIN;

    int maxPathSum(TreeNode* root) 
    {
        maxGain(root);
        return res;
    }

    int maxGain(TreeNode* node)
    {
        if(!node)
        return 0;

        int leftGain = max(0, maxGain(node->left));
        int rightGain = max(0, maxGain(node->right));

        int gain = node -> val + leftGain + rightGain;

        res = max(res, gain);
        return node -> val + max(leftGain, rightGain);


    
    }


};
