class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        //we need a solution that runs on o(logn)
        //return index of target

        int l = 0;
        int r = nums.size() - 1;

        while(l <= r)
        {
            int m = l + (r - l)/2;

            if(nums[m] == target)
            {
                return m;
            }

            //in the left sorted array
            if(nums[l] <= nums[m])
            {
                if(target > nums[m])
                {
                    l = m + 1 ;
                }
                    else if(target < nums[l])
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m - 1;
                    }
            }
            else
            {
                if(target < nums[m])
                {
                    r = m - 1;
                }
                /// else if(target > nums[m])
                else
                {
                    if(target <= nums[r])
                    {
                        l = m + 1;
                    }
                    else
                    {
                        r = m - 1;
                    }
                }
            }
            //m is in the right sorted array

        }
        return -1; 
    }
};
