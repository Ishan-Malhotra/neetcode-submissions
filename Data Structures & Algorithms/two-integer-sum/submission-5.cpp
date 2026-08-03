class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map <int, int> list;

        for(int i = 0; i < nums.size(); i++)
        {
            list[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int j = target - nums[i];

            if(list.count(j) && list[j] != i)
            {
                return {i, list[j] };
            }  
        }

        return {};
    }
};
