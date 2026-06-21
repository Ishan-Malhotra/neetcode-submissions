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
    int goodNodes(TreeNode* root) 
    {
        //current node = max
        //recursively go from each node to current node and check if a value is big
        //nahi toh count++

        int count = 0;
        dfs(root, root -> val, count);
        return count;

    }

    void dfs (TreeNode* node, int maxval, int &count)
    {
        if(!node)
        return;


        //as we arrive at this node, no value should be bigger than maxval
        if(node -> val >= maxval)
        {
            count++;
            maxval = node ->val; 
        }

        //now recursively travel the left and right paths
        dfs(node -> left, maxval, count);
        dfs(node -> right, maxval, count);
    }


};
