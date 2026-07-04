class Solution {
public:

    vector<string> res;

    vector<string> generateParenthesis(int n) 
    {
        string cur;
        backtrack(n,0,0,cur);
        return res;
    }

    void backtrack(int n, int openN, int closeN, string &cur)
    {
        if (openN == closeN && openN == n)
        {
            res.push_back(cur);
            return;
        }

        if(openN < n) 
        {
            cur += '(';
            backtrack(n, openN+1, closeN, cur);
            cur.pop_back();
        }

        if(closeN < openN)
        {
            cur+= ')';
            backtrack(n, openN, closeN+1, cur);
            cur.pop_back();
        }
    }


};
