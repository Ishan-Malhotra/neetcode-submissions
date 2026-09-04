class Solution {
public:

    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        if(n == 1)
        return nums[0];

        if(n == 2)
        return max(nums[0], nums[1]);

        vector<int> cacheA(nums.size(), -1);
        vector<int> cacheB(nums.size(), -1);

        return max(dfs(0,n-2, nums, cacheA), dfs(1, n-1, nums, cacheB));
    }

    int dfs(int i, int end, vector<int> &nums, vector<int> &cache)
    {
        if(i > end)
        return 0;

        if(cache[i] != -1)
        return cache[i];

        cache[i] = max( nums[i] + dfs(i+2, end, nums, cache), dfs(i+1, end, nums, cache));
        return cache[i];
    }
};
