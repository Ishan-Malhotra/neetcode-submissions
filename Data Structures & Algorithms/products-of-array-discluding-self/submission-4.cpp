class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int prod = 1;
        int zeroCount = 0;

        vector<int> result(nums.size());

        for(int n:nums)
        {
            if(n!=0)
            {
                prod = prod * n;
            }
            else
            {
                zeroCount++;
            }
        }

        if(zeroCount > 1)
        {
            return result;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(zeroCount > 0)
            {
                if(nums[i] == 0)
                {
                    result[i] = prod;
                }
                else
                result[i] = 0;
            }
            else
            result[i] = prod/nums[i];
        }

        return result;

    
    }
};
