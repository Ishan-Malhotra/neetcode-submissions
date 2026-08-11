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

    struct Compare
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a -> val > b -> val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue <ListNode*, vector<ListNode*>, Compare> minHeap;

        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        for(const auto & list : lists)
        {
            if(list != nullptr)
            {
                minHeap.push(list);
            }
        }

            //now minheap contains all the non nullptr heads

            while(!minHeap.empty())
            {
                ListNode* minNode = minHeap.top();
                minHeap.pop();

                tail -> next = minNode;
                tail = tail -> next;

                if(minNode -> next != nullptr)
                {
                    minHeap.push(minNode-> next);
                }
            }

        return head -> next;
    }
};
