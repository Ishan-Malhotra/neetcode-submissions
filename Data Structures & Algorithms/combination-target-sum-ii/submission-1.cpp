class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        
        vector<int> cur;

        dfs(0, nums, cur, target);
        return res;
    }

    void dfs(int i, vector<int>&nums, vector<int> &cur, int target)
    {

        if(target == 0)
        {
            res.push_back(cur);
            return;
        }

        if(target < 0 || i >= nums.size())
        {
            return;
        }

        //choose to include nums[i]
        cur.push_back(nums[i]);
        dfs(i, nums, cur, target - nums[i]);


        //choose not to include
        cur.pop_back();
        dfs(i+1, nums, cur, target);

    }
};
