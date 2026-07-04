class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector <int> cur;
        dfs(0, cur, nums);
        return res;
    }

    void dfs(int i, vector<int> &cur, vector<int> &nums)
    {
        if(i == nums.size())
        {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(i+1, cur, nums);
        cur.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1])
        {
            i++;
        }
        dfs(i+1, cur, nums);

    }
};
