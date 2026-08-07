class Solution {
public:
    bool isPalindrome(string s) 
    {
        int n = s.size();
        int l = 0;
        int r = s.size() - 1;

        while(l < r)
        {
            while((l < n) && !isAlphaNum(s[l]))
            {
                l++;
            }

            while (r >= 0 && !isAlphaNum(s[r]))
            {
                r--;
            }

            if(tolower(s[l]) != tolower(s[r]))
            return false;

            l++;
            r--;

        }
        return true;
        
    }

    bool isAlphaNum(char c)
    {
        return ((c >= 'a') && (c <= 'z') || (c >= 'A') && (c <= 'Z') || (c >= '0') && (c <= '9'));
    }
};
