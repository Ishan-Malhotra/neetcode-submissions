class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size() != t.size())
        return false;

        unordered_map <char, int> s1;
        unordered_map <char, int> t1;

        for(char c: s)
        {
            s1[c]++;
        }

         
        for(char c: t)
        {
            t1[c]++;
        }

        if(s1 == t1)
        return true;
        else
        return false;
    }
};
