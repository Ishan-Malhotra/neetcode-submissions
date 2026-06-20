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
        set <int> s;

        collect (root, s);
        //now s should be full

        auto it = s.begin();
        advance(it, k-1);

        return *it;

        //now return value at k+1th postion in s
        //how do i do tha
    }

    void collect(TreeNode* root, set<int>& s)
    {
        if(!root)
        return;

        s.insert(root -> val);
        collect(root ->left, s);
        collect(root -> right, s);
    }
};
