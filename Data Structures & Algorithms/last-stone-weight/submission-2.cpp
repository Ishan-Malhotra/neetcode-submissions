class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue <int> maxHeap;

        for(int stone: stones)
        {
            maxHeap.push(stone);
        }

        if(maxHeap.empty())
        {
            return 0;
        }

        while(maxHeap.size() > 1)
        {
            
            //y is heavier than x

            int y = maxHeap.top();
            maxHeap.pop();

            int x = maxHeap.top();
            maxHeap.pop();

            if(x == y)
            continue;

            else if(x < y)
            {
                int z = y - x;
                maxHeap.push(z);
            }
        }

        if(maxHeap.empty())
        {
            return 0;
        }
        else
        return maxHeap.top();
    }
};
