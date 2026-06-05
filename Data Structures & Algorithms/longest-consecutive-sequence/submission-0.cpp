class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.empty())
        return 0;
        
        sort(nums.begin(), nums.end());
        
        int length = 1;
        int maxlength = 1;

        for(int i = 0; i < nums.size()-1; i++)
        {

            //A. Consecutive keys are duplicates
            if(nums[i+1] == nums[i])
            continue;

            //B. Consecutive keys are consecutive numbers 

            if(nums[i+1] - nums[i] == 1)
            {
                length++;
            }

            else
            {
            maxlength = max(maxlength, length);
            length = 1;
            }
        }
        
        return max(maxlength, length);
    }
};
