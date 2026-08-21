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

    priority_queue <int, vector<int>, greater<int>> minHeap;

    int kthSmallest(TreeNode* root, int k) 
    {
        dfs(root);

        for(int i = 1; i < k; i++)
        {
            minHeap.pop();
        }

        int res = minHeap.top();
        return res;

    }

    void dfs(TreeNode* node)
    {
        if(!node)
        return;

        minHeap.push(node-> val);
        dfs(node -> left);
        dfs(node -> right);

    }
};
