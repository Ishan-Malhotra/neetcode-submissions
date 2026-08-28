class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set <int> list(nums.begin(), nums.end());
        if(list.size() == 1) return 1;

        int maxstreak = 0;

        for(int i : list)
        {
            if(list.find(i-1) == list.end())
            {
                int currentNum = i;
                int streak = 1;
                //when i-1 does not exist
                while(list.find(i+1) != list.end())
                {
                    i++;
                    streak++;
                }
                maxstreak = max(streak, maxstreak);
            }
        }
        return maxstreak;  
    }
};
