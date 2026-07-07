class Solution {
public:

    vector<vector<string>> res;

    vector<vector<string>> partition(string s) 
    {
        vector<string> cur;
        dfs(0,0, cur, s);
        return res;
    }

    void dfs(int j, int i, vector<string> &cur, string &s)
    {
        if(i >= s.size())
        { 
            if(i == j)
            res.push_back(cur);
            return;
        }

        if(isPali(j, i,s))
        {
            cur.push_back(s.substr(j, i-j+1));
            dfs(i+1, i+1, cur, s);
            cur.pop_back();
        }
        dfs(j, i+1, cur, s);
    }


    bool isPali(int p, int q, string &s)
    {
        while (p <= q)
        {
            if(s[p] != s[q])
            return false;
            p++;
            q--;
        }
        return true;
    }
};

