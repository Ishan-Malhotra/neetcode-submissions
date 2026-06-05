class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {

        unordered_map <int, int> count;
        //[frequency, number]

        for(int num : nums)
        {
            count[num]++;
        }

        //numbers and their corresponding frequencies saved in hash table
        
        vector < pair < int, int > > arr;

        for(const auto &p : count)
        {
            arr.push_back({p.second, p.first});
        }

        //made a dynamic vector which has freq -> value
        
        sort(arr.rbegin(), arr.rend());
        vector <int> ans;

        for(int i = 0; i < k; i++)
        {
            ans.push_back(arr[i].second);
        }
        return ans;
        
    }
};
