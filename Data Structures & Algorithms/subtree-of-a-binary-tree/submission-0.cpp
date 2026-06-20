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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        //empty tree is always a subtree

        if(!subRoot)
        return true;

        //root exist nahi karti but subroot exist karta hai = bullshit
        if(!root)
        return false;

        //essentially we just check if two trees are equal

        if(isSameTree(root, subRoot))
        return true;

        if( isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot))
        return true;
        else
        return false;

        
    }

    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        return true;

        if(!p || !q)
        return false;

        if ( p && q && p -> val == q -> val )
        return (isSameTree(p-> left, q -> left) && (isSameTree(p -> right, q -> right)));
        else
        return false;

    }
};
