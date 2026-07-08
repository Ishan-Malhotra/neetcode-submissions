class Solution {
public:

    vector<string> res;

    vector<string> generateParenthesis(int n) 
    {
        string cur;
        dfs(0,0,cur, n);
        return res;
    }

    void dfs(int openN, int closeN, string &cur, int n)
    {
        if(openN == closeN && openN == n)
        {
            res.push_back(cur);
            return;
        }

        if(openN < n)
        {
            cur+='(';
            dfs(openN+1,closeN, cur,n);
            cur.pop_back();
        }
        if(closeN < openN)
        {
            cur+=')';
            dfs(openN, closeN+1, cur, n);
            cur.pop_back();
        }

    }
};
