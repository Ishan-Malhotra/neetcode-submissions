#include <bits/stdc++.h>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map <int, int> freqCount;
        for(int n : nums)
        {
            freqCount[n]++;
        }

        priority_queue < pair<int,int>> maxHeap;

        for(auto pair : freqCount)
        {
            maxHeap.push({pair.second, pair.first});
        }

        vector<int> res;

        for(int i = 0; i < k; i++)
        {
            auto node = maxHeap.top();
            maxHeap.pop();
            res.push_back(node.second);
        }

        return res;
    }
};
