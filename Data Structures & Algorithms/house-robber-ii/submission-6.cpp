class Solution {
public:

    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        if(n == 0)
        return 0;

        if(n == 1)
        return nums[0];

        vector<int> memoA (n, -1);
        vector<int> memoB (n, -1);

        return max(dfs(nums, 0, n-2, memoA), dfs(nums, 1, n-1, memoB));

    }

    int dfs(vector<int> &nums, int i, int end, vector<int> &memo)
    {
        if(i > end)
        return 0;

        if(memo[i] != -1)
        return memo[i];

        memo[i] =  max(nums[i] + dfs(nums, i+2, end, memo), dfs(nums, i+1, end, memo));
        return memo[i];

    }
};
