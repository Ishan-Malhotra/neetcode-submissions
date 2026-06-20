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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root)
        return nullptr;


        //if head(p) = child(q) return head 
        //mainly humme head return karna hai such that both p and q are children

        //1. if p is smaller than root and q is greater than root, we are in the correct place
        

        if( p -> val < root -> val && q -> val < root -> val)
        return lowestCommonAncestor(root-> left, p, q);

        else if( p -> val > root -> val && q -> val > root -> val)
        return lowestCommonAncestor(root -> right, p, q);

        else
        return root;
        
    }
};
