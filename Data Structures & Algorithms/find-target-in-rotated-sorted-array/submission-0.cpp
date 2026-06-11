class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        //brute force
        int i = 0;

        for(int num : nums)
        {
            
            if(num == target)
            {
                return i;
            }
            i++;

        }
        return -1;
        
    }
};
