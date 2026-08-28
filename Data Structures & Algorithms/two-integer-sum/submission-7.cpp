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
            int cur = target - nums[i];

            if(list.count(cur) && list[cur] != i)
            {
                return{i, list[cur]};
            }
        }

        return {};
    }
};
