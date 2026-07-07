class Solution {
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s) 
    {
        vector<string> cur;
        dfs(0,0,s,cur);
        return res; 
    }

    void dfs(int j, int i, string &s, vector<string> &cur)
    {
        if(i >= s.size())
        {
            if(i == j)
            res.push_back(cur);

            return;
        }

        if(isPali(j,i, s))
        {
            cur.push_back(s.substr(j, i-j+1));
            dfs(i+1, i+1,s, cur);
            cur.pop_back();
        }
    dfs(j, i+1, s, cur);

    }

    bool isPali(int p, int q, string l)
    {
        while(p < q)
        {
        if(l[p] != l[q])
        return false;

        p++;
        q--;

        }
        return true;
    }
};
