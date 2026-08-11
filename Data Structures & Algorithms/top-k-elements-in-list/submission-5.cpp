class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map <int, int> freqMap;

        for(int num:nums)
        {
            freqMap[num]++;
        }

        priority_queue < pair<int,int> ,vector <pair<int,int>> , greater <pair<int,int>>> Heap;

        for(const auto & freq: freqMap)
        {
            Heap.push({freq.second, freq.first});
            if(Heap.size() > k)
            {
                Heap.pop();
            }
        }

        vector<int> res;

        for(int i = 0; i < k; i++)
        {
            res.push_back(Heap.top().second);
            Heap.pop();
        }

        return res;
    }
};
