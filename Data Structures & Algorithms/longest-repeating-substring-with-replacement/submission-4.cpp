class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int l = 0;
        int res = 0;
        unordered_map <char, int> freq;
        int maxfreq = 0;

        for(int r = 0; r < s.size(); r++)
        {
            freq[s[r]]++;
            maxfreq = max(maxfreq, freq[s[r]]);

            while((r-l+1) - maxfreq > k)
            {
                freq[s[l]]--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
