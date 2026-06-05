class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set <int> inventory(nums.begin(), nums.end());
        //unique individual items stored
        int maxStreak = 0;

        //we cant do sort, cause o(logn)
        for(int num : inventory)
        {
            if(inventory.find(num-1) == inventory.end())
            {
                int currNum = num;
                int currStreak = 1;

                while(inventory.find(currNum + 1) != inventory.end())
                {
                    currNum++;
                    currStreak++;
                }
                maxStreak = max(maxStreak, currStreak);
            }

            

        }

        return maxStreak;


        
    }
};
