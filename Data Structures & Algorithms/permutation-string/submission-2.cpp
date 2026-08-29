class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size() > s2.size())
        return false;

        vector<int> s1t (26, 0);
        vector<int> s2t (26, 0);

        for(int i = 0; i < s1.size(); i++)
        {
            s1t[s1[i]- 'a']++;
            s2t[s2[i] - 'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++)
        {
            if(s1t[i] == s2t[i])
            matches++;
        }

        int l = 0;
        for(int r = s1.size(); r < s2.size(); r++)
        {
            if(matches == 26)
            return true;

            //add incoming char s2[r]
            int index = s2[r] - 'a';
            s2t[index]++;

            if(s1t[index] == s2t[index])
            matches++;
            else if(s1t[index] + 1 == s2t[index])
            matches--;

            index = s2[l] - 'a';
            s2t[index]--;

            if(s1t[index] == s2t[index])
            matches++;
            else if(s1t[index]-1 == s2t[index])
            matches--;


            l++;
        }
        return matches == 26;

    }
};
