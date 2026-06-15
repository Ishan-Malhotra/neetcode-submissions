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
    vector<int> rightSideView(TreeNode* root)
    {
        vector <int> ans;

        if(!root)
        return {};

        //we traverse all nodes, we remember the rightmost node and add it to our ans

        queue <TreeNode*> q;
        q.push(root);
        

        while(q.size()>0)
        {
            int size = q.size();

            for(int i = 0; i < size; i++)
            {
            TreeNode* curr = q.front();
            q.pop();

            if(i == size - 1)
            {
                ans.push_back(curr -> val);
            }

            if(curr -> left)
            q.push(curr -> left);

            if(curr -> right)
            q.push(curr -> right);

            //jo q mei last mei push hua hai, vo rightmost hoga
            

            }
        }

        return ans;
    }
};
