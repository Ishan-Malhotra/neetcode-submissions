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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
    
        if(preorder.empty() || inorder.empty())
        return nullptr;

        //preorder ka first would be our head node
        TreeNode* root = new TreeNode(preorder[0]);
        
        //now find index of root inside the inorder vector
        

        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> leftIn(inorder.begin(), inorder.begin() + mid); //the value at the end is excluded
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        //mid is the no of elements in the left subtree

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());

        root -> left = buildTree(leftPre, leftIn);
        root -> right = buildTree(rightPre, rightIn);

        return root;

        
    }
};
