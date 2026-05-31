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
    void reorderList(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = head -> next;

        while (fast && fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // now slow should be at the midpoint


        ListNode* second = slow -> next;
        slow -> next = nullptr;  //second half is broken from the main list

        //reversing the second half of the list

        ListNode* before = nullptr;
        ListNode* after = second -> next;

        while (second)
        {
            after = second -> next;
            second -> next = before;

            before = second;
            second = after;
        }

        //second half has been reversed
        //before is now the head of the second linkedlist

        ListNode* first = head;
        second = before;

        ListNode* temp1 = first -> next;
        ListNode* temp2 = second -> next;

        while(second)
        {
            temp1 = first -> next;
            temp2 = second -> next;

            first -> next = second;
            second -> next = temp1;

            first = temp1;
            second = temp2;

        }
        
    }
};
