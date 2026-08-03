class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        set <char> list;
        int l = 0;
        int length = 0;

        for(int r = 0; r < s.size(); r++)
        {
            while(list.find(s[r]) != list.end())
            {
                list.erase(s[l]);
                l++;
            }
            list.insert(s[r]);
            length = max(length, r-l+1);

        }
        return length;
    }
};
