class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> cur;
        vector<bool> visited(nums.size(), false);
        dfs(nums, cur, visited);
        return res;
    }

    void dfs(vector<int>& nums, vector<int> &cur, vector <bool> &visited)
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
                visited[i] = true;
                cur.push_back(nums[i]);
                dfs(nums, cur, visited);
                cur.pop_back();
                visited[i] = false;

            }
        }
    }
};
