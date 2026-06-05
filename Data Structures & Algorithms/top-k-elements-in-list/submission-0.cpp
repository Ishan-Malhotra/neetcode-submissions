class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());

        unordered_map <int, int> count;
        //[frequency, number]

        for(int num : nums)
        {
            count[num]++;
        }

        vector < pair<int, int> > arr;

        for(const auto & p: count)
        {
            arr.push_back({p.second, p.first});
        }

        //so now we have frequencies as keys and values as values
        //sort in descending orfer

        sort(arr.rbegin(), arr.rend());

        vector <int> res;

        for(int i = 0; i < k; i++)
        {
            res.push_back(arr[i].second);
        }

        return res;
        
    }
};
