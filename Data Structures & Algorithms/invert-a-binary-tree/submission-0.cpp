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


 //using BFS

 //using stacks instead of queues?


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {   
        if(!root)
        {
            return nullptr;
        }    


        queue <TreeNode*> myQueue;
        myQueue.push(root);

        while(myQueue.size() > 0)
        {
            TreeNode* currentNode = myQueue.front();
            myQueue.pop();

            swap(currentNode -> left, currentNode -> right);

            if(currentNode -> left)
            {
                myQueue.push(currentNode -> left);
            }
            if(currentNode -> right)
            {
                myQueue.push(currentNode -> right);
            }
        }
        return root;
    }
};
