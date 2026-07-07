class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) 
    {
        if(nums.empty())
        {
            return {{}};
        }

        vector<int> cur;
        vector<bool> pick (nums.size(), false);

        dfs(cur, nums, pick);
        return res;
    }

    void dfs(vector<int> &cur, vector<int> &nums, vector<bool> pick)
    {
        if(cur.size() == nums.size())
        {
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!pick[i])
            {
                cur.push_back(nums[i]);
                pick[i] = true;
                dfs(cur, nums, pick);
                cur.pop_back();
                pick[i] = false;
            }
            
        }

    }
};
