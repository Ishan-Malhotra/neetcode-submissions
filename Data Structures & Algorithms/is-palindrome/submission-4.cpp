class Solution {
public:

    bool isPalindrome(string s) 
    {
        int n = s.size();
        int l = 0;
        int r = n-1;

    
        while(l < r)
        {
            while((l < r) && !isAlphaNum(s[l]))
            l++;

            while(l < r && !isAlphaNum(s[r]))
            r--;

            if(tolower(s[l]) != tolower(s[r]))
            {
               return false;
            }
            
            l++;
            r--;
        }

        return true;
    }

    bool isAlphaNum(char c)
    {
        if (((c <= 'z') && (c >= 'a')) || ((c <= 'Z') && (c >= 'A')) || (c >= '0' && c <= '9'))
        return true;
        else
        return false;
    }
};
