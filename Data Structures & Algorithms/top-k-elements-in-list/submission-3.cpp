class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map <int, int> freq;

        for(const auto &n : nums)
        {
            freq[n]++;
        }

        //now we have a frequency counter;

        vector <pair<int,int>> res;

        for(const auto &f: freq)
        {
            res.push_back({f.second, f.first});
        }

        sort(res.rbegin(), res.rend());

        vector <int> result;

        for(int i = 0; i < k; i++)
        {
            result.push_back(res[i].second);
        }

        return result;
        
    }
};
