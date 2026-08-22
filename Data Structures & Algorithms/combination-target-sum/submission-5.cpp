class Solution {
public:

    vector<vector<int>> res;
    int sum = 0;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<int> cur;
        dfs(nums, cur, target, 0, 0);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> &cur, int target, int total, int i)
    {
        if(total == target)
        {
            res.push_back(cur);
            return;
        }

        if(i >= nums.size() || total > target)
        return;

        //include i

        cur.push_back(nums[i]);
        dfs(nums, cur, target, total + nums[i], i);
        cur.pop_back();
        dfs(nums, cur, target, total , i+1);

        
    }
};
