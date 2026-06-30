class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map <int, int> list;

        for(int i = 0; i < nums.size() ; i++)
        {
            list[nums[i]] = i;
        }

        //nums[i] + nums[j] == target
        //nums[j] = target - nums[i]
        //if nums[j] exists in lists we have i and j

        for(int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];

            if(list.count(temp) && list[temp] != i)
            {
                return {i, list[temp]};
            }
        }

        return {};

    }
};
