class Solution {
public:
    string minWindow(string s, string t) 
    {
       
        if(s.size() < t.size())
        return "";
        
        unordered_map <char, int> tmap;

        //tmap filling
        for(int i = 0; i < t.size(); i++)
        {
            tmap[t[i]]++;
        }

        int need = tmap.size();
        int have = 0;

        int l = 0;
        //to store indexes for output
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;

        unordered_map <char, int> window;
        for(int r = 0; r < s.size(); r++)
        {
            char c = s[r];
            window[c]++;

            if(tmap.count(c) && window[c] == tmap[c])
            have++;

            while(have == need)
            {
                if(r-l+1 < resLen)
                {
                    resLen = r-l+1;
                    res = {l,r};
                }

                window[s[l]]--;

                if(tmap.count(s[l]) && window[s[l]] < tmap[s[l]])
                {
                    have--;
                }
                l++;
            }  
        }

        int la = res.first;
        int ra = res.second; 

        return resLen == INT_MAX ? "" : s.substr(la, ra-la+1);
    }
};
