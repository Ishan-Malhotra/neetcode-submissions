class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<int> cur;
        int total;
        dfs(0, nums, target, cur, 0);
        return res;
    }

    void dfs(int i, vector<int> &nums, int target, vector<int> &cur, int total)
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

        //include nums[i]
        cur.push_back(nums[i]);
        dfs(i, nums, target, cur, total+nums[i]);

        //dont include nums[i]
        cur.pop_back();
        dfs(i+1, nums, target, cur, total);

    }


};
