class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map <int, int> freqMap;
        //[frequency, number]

        for(const auto &n: nums)
        {
            freqMap[n]++;
        }

        //now frequencies have been marked in the hash table
        //now we push all entries of the hash table as a vector

        vector <pair<int,int>> res;

        for(const auto & f: freqMap)
        {
            res.push_back({f.second, f.first});
        }

        sort(res.rbegin(), res.rend());
        //sorted in descending order

        vector <int> result;

        for(int i = 0; i < k; i++)
        {
            result.push_back(res[i].second);
        }
        return result;
    }
};
