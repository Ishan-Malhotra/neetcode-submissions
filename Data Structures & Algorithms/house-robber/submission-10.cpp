class Solution {
public:

    vector<int> memo;

    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        memo.resize(n, -1);

        return dfs(0, nums);
    }

    int dfs(int i,vector<int>& nums)
    {
        if(i >= nums.size())
        return 0;
        
        if(memo[i] != -1)
        return memo[i];
        
        memo[i] = max(dfs(i+1, nums), nums[i] + dfs(i+2, nums));
        return memo[i];
        
    }
};
