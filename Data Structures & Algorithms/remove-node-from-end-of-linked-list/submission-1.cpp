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
        int N = 0;
        ListNode *temp = head;

        while(temp)
        {
            N++;
            temp = temp -> next;
        }
        
        //now N = number of nodes
        int removeIndex = N - n; 

        if (removeIndex == 0)
        {
            return head -> next;
        }

        temp = head;
        for (int i = 0; i < removeIndex - 1; i++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        return head;

        
    }
};
