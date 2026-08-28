class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l = 0;
        unordered_set <char> list;
        int res = 0;

        for(int r = 0; r < s.size(); r++)
        {
            while(list.count(s[r]))
            {
                list.erase(s[l]);
                l++;
                //cout << "l = " << s[l] << endl;
            }
            //not in list;
            list.insert(s[r]);
            //cout << "r = " << s[r] << endl;
            res = max(res, r-l+1);
        }
        return res;
    }
};
