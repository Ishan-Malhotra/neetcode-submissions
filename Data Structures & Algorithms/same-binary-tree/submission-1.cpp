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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        if (!p && !q)
        return true;

        if (!p || !q)
        return false;

        queue <TreeNode*> q1;
        queue <TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while((q1.size() > 0) && (q2.size() > 0))
        {
            TreeNode* c1 = q1.front();
            TreeNode* c2 = q2.front();

            q1.pop();
            q2.pop();

            if(!c1 && !c2)
            continue;

            if(!c1 || !c2)
            return false;

            if(c1 -> val != c2 -> val)
            return false;

           
            q1.push(c1 -> left);

        
            q2.push(c2 -> left);

            
            q1.push(c1 -> right);

     
            q2.push(c2 -> right);

        }
        return true;
    }
};
