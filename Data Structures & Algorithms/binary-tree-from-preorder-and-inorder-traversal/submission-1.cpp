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
        
        TreeNode* root = new TreeNode(preorder[0]);

        //find root in inorder that divides it into left half and right half

        //now find index of root inside our inorder node
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector <int> leftInorder (inorder.begin(), inorder.begin()+mid);
        vector <int> rightInorder (inorder.begin() + mid + 1, inorder.end());

        //mid is the number of elements in the left subtree

        vector <int> leftPreorder(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector <int> rightPreorder(preorder.begin() + mid + 1, preorder.end());

        root -> left = buildTree(leftPreorder, leftInorder);
        root -> right = buildTree(rightPreorder, rightInorder);

        return root;
        
    }
};
