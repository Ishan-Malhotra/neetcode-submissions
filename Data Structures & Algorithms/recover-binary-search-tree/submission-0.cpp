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

    vector <TreeNode*> res;

    void recoverTree(TreeNode* root) 
    {
        inorder(root);

        TreeNode* node1 = nullptr;
        TreeNode* node2 = nullptr;

        for(int i = 0; i < res.size()-1; i++)
        {
            if(res[i] -> val > res[i+1]-> val)
            {
                node2 = res[i+1];

                if(!node1)
                node1 = res[i];

                else
                break;
            }
        }
        swap(node1-> val, node2-> val);
    }

    void inorder(TreeNode* node)
    {
        if(!node)
        return;

        if(node -> left)
        {
            inorder(node-> left);
        }

        res.push_back(node);

        if(node -> right)
        {
            inorder(node -> right);
        }
    }
};