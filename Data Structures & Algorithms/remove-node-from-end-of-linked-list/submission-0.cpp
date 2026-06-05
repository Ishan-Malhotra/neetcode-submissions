/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {

        vector <ListNode*> Nodes;
        ListNode* temp = head;

        while(temp)
        {
            Nodes.push_back(temp);
            temp = temp -> next;
        }

        //LinkedList converted to a vector

        int length = Nodes.size();
        int indexToRemove = length - n;

        if(indexToRemove == 0)
        return head -> next;

        else
        Nodes[indexToRemove - 1] -> next = Nodes [indexToRemove] -> next;
        return head;

        
    }
};
