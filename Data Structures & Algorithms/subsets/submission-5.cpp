class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> subsets(vector<int>& nums) 
    {   
        vector<int> cur;
        dfs(0, cur, nums);
        return res;
    }

    void dfs(int i, vector <int> &cur, vector<int> &nums)
    {
        if(i == nums.size())
        {
            res.push_back(cur);
            return;
        }

        //include nums[i]
        cur.push_back(nums[i]);
        dfs(i+1, cur, nums);
        

        cur.pop_back();
        dfs(i+1, cur, nums);

    }
};
