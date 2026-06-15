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
        if(!root)
        return 0;


        int ans = 0;
        int m = root -> val;

        queue <pair <TreeNode*, int>> q;
        q.push({root, root -> val});

        while(q.size() > 0)
        {
            auto [curr, maxval] = q.front();
            q.pop();

            if(curr -> val >= maxval)
            {
            ans++;
            }

            if(curr -> left)
            q.push({curr -> left, max(maxval, curr-> val)});

            if(curr -> right)
            q.push({curr -> right, max(maxval, curr -> val)});
        }
        return ans;
        
    }
};
