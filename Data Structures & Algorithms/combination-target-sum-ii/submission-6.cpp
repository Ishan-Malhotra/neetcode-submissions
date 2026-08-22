class Solution {
public:

    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(candidates, target, 0, cur, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, int total, vector<int> &cur, int i)
    {
        if(total == target)
        {
            res.push_back(cur);
            return;
        }

        if(i >= candidates.size() || total > target)
        return;

        
    
        cur.push_back(candidates[i]);
        dfs(candidates, target, total + candidates[i], cur, i+1);
        cur.pop_back();

        while(i+1 < candidates.size() && candidates[i] == candidates[i+1])
        {
            i++;
        }
        dfs(candidates, target, total , cur, i+1);


    }
};
