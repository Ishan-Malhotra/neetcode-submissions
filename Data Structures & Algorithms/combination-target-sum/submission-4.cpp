class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<int> cur;
        dfs(0, nums, cur, target, 0);
        return res;
    }

    void dfs(int i, vector <int> &nums, vector<int> &cur, int target, int total)
    {
        if(total == target)
        {
            res.push_back(cur);
            return;
        }

        if(i >= nums.size() || total > target)
        {
            return;
        }

        cur.push_back(nums[i]);
        dfs(i, nums, cur, target, total + nums[i]);

        cur.pop_back();
        dfs(i+1, nums, cur, target, total);
    }
};
