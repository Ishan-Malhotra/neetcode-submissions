class Solution {
public:

    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());

        dfs(0, candidates, cur, target, 0);
        return res;
    }

    void dfs(int i, vector<int> & candidates, vector<int> & cur, int target, int total)
    {

        if(total == target)
        {
            res.push_back(cur);
            return;
        }

        if(i >= candidates.size() || total > target)
        return;

        

        //include candidates[i]

        cur.push_back(candidates[i]);
        dfs(i+1, candidates, cur, target, total + candidates[i]);

        //do not include
        cur.pop_back();

        while( i+1 < candidates.size() && candidates[i] == candidates[i+1])
        i++;

        dfs(i+1, candidates, cur, target, total);

    }

};
