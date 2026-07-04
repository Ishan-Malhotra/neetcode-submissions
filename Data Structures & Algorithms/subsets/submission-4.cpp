class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> subset;

        dfs(0,nums,subset,res);
        return res;
    }

    void dfs(int index, vector<int>&nums, vector<int> &subset, vector<vector<int>> &res)
    {
        if(index == nums.size())
        {
            res.push_back(subset);
            return;
        }

        //include nums[index]
        subset.push_back(nums[index]);
        dfs(index+1, nums, subset, res);

        //do not include
        subset.pop_back();
        dfs(index+1, nums, subset, res);

        return;
        
    }
};
