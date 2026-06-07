/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        //first pass

        unordered_map <Node*,Node*> oldToCopy;

        Node* temp = head;
        while(temp)
        {
            Node* copy = new Node(temp -> val);
            oldToCopy[temp] = copy;
            temp = temp -> next;
        }

        //second pass: now we map the random pointer

        temp = head;

        while(temp)
        {
            Node* copy = oldToCopy[temp];
            copy -> next = oldToCopy[temp -> next];
            copy -> random = oldToCopy[temp -> random];
            temp = temp -> next;
        }

        return oldToCopy[head];
    }
};
