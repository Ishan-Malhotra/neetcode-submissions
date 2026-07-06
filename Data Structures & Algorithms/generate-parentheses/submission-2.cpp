class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) 
    {
        //curr
        string cur;
        dfs(n, cur, 0, 0);
        return res;
    }

    void dfs(int n, string &cur, int openN, int closeN)
    {
        if(openN == closeN && openN == n)
        {
            res.push_back(cur);
            return;
        }

        if(openN < n)
        {
            cur += '(';
            dfs(n, cur, openN+1, closeN);
            cur.pop_back();
        }

        if(closeN < openN)
        {
            cur += ')';
            dfs(n, cur, openN, closeN +1);
            cur.pop_back();
        }

    }

};
