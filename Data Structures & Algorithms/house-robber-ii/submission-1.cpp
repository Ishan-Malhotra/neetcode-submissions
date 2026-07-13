class Solution {
public:

    

    int rob(vector<int>& nums) 
    {
        int n = nums.size();

        if(n == 1)
        return nums[0];


        //SCENE A: 0 to n-2
        vector<int> memoA(n, -1);
        int optionA = dfs(nums, 0, n-2, memoA);

        //SCENE B: 1 to n-1
        vector<int> memoB(n, -1);
        int optionB = dfs(nums, 1, n-1, memoB);

        return max(optionA, optionB);

    }

    int dfs(vector<int> &nums, int i, int end, vector <int> &memo)
    {
        if(i > end)
        {
            return 0;
        }

        if(memo[i] != -1)
        return memo[i];

        memo[i] = max(dfs(nums, i+1, end, memo), nums[i] + dfs(nums, i+2, end, memo));
        return memo[i];
    }
};
