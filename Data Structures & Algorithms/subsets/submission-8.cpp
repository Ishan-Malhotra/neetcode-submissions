class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> cur;
        dfs(nums, cur, 0);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> &cur, int i)
    {
        //you can either include i in cur or you may not include i in cur

        if(i == nums.size())
        {
            res.push_back(cur);
            return;
        }

        //include
        cur.push_back(nums[i]);
        dfs(nums, cur, i+1);

        cur.pop_back();
        dfs(nums, cur, i+1);
    }
};
