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
            int temp = target - nums[i];

            //does temp exist in our hash map?
            if((list.find(temp) != list.end()) && (list.find(temp) -> second != i))
            {
                //yes
                return {i, list.find(temp) -> second};
            }


        }
        return {};

        
        
    }
};
