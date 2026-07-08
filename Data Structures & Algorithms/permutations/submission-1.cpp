class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> cur;
        vector<bool> visited (nums.size(), false);
        dfs(cur, nums, visited);
        return res;
    }

    void dfs(vector<int> &cur, vector<int> &nums, vector<bool> &visited)
    {
        if(cur.size() == nums.size())
        {
            res.push_back(cur);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(!visited[i])
            {
                cur.push_back(nums[i]);
                visited[i] = true;
                dfs(cur, nums, visited);
                cur.pop_back();
                visited[i] = false;
            }
        }
    }
};
