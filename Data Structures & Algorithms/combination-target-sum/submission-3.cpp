class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    {
        vector<int> cur;
        int total;
        backtrack(0, cur, nums,target, 0);
        return res;
    }

    void backtrack(int i, vector<int> &cur, vector<int> &nums, int target, int total)
    {
        if(total == target)
        {
            res.push_back(cur);
            return;
        }

        //remove the out of bounds error

        if(i >= nums.size() || total > target)
        return;

        //include nums[i]
        cur.push_back(nums[i]);
        backtrack(i, cur, nums, target, total+nums[i]);

        cur.pop_back();
        backtrack(i+1, cur, nums, target, total);


    }
};
