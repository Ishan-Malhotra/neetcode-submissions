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
    int kthSmallest(TreeNode* root, int k) 
    {
        vector <int> list;
        dfs(root, list);

        return list[k-1];
        
    }

    void dfs(TreeNode* node, vector <int> &list)
    {
        if(node -> left)
        dfs(node -> left, list);

        list.push_back(node -> val);

        if(node -> right)
        dfs(node -> right, list);
    }
};
