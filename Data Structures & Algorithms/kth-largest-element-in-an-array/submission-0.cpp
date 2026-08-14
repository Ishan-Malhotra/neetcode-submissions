class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue <int, vector<int>, greater<int>> q;

        //this is a minheap

        for(int num: nums)
        {
            q.push(num);
        }

        while(q.size()> k)
        {
            q.pop();
        }

        return q.top();


        
    }
};
