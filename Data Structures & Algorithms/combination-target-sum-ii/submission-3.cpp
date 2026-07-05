class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(0, cur, candidates, target, 0);
        return res;
    }

    void dfs(int i, vector<int> &cur, vector<int> & candidates, int target, int total)
    {
        if(total == target)
        {
            res.push_back(cur);
            return;
        }

        //out of bounds
        if(i >= candidates.size() || total > target)
        {
            return;
        }

        //include 
        cur.push_back(candidates[i]);
        dfs(i+1 ,cur, candidates, target, total+candidates[i]);
        cur.pop_back();

        while (i+1 < candidates.size() && candidates[i] == candidates[i+1])
        {
            i++;
        }

        dfs(i+1, cur, candidates, target, total );
    }
};
