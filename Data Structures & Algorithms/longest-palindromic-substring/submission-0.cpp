class Solution {
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        int reslen = 0;
        int resinx = 0;

        vector < vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i; j <=n-1; j++)
            {
                if(s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1]))
                {
                    dp[i][j] = true;
                    int slen = j - i + 1;

                    if(reslen <= slen)
                    {
                        reslen = slen;
                        resinx = i;
                    }
                }
            }
        }

        return s.substr(resinx, reslen);
        
    }
};
