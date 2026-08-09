class Solution {
public:

    unordered_map <int, bool> memo;

    //memo[i] = t/f -> can be segmented or cannot be segmented

    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.size();
        memo[n] = true;
        return dfs(s, wordDict, 0);
    }

    bool dfs(string &s, vector <string>& wordDict, int i)
    {
        if(memo.find(i) != memo.end())
        {
            return memo[i];
        }

        for(const auto & w: wordDict)
        {
            if(i + w.size() <= s.size() && s.substr(i, w.size()) == w)
            {
               if(dfs(s, wordDict, i + w.size()))
               {
                memo[i] = true;
                return true;
               }
            }
        }

        memo[i] = false;
        return false;
    }
};
