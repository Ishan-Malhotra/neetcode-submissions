class Solution {
public:

   

    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> res;
        unordered_map < string, vector<string>> list;

        for(string s: strs)
        {
            string cur = s;
            sort(cur.begin(), cur.end());
            list[cur].push_back(s);
        }

        for( auto & str: list)
        {
            res.push_back(str.second);
        }
        return res;
        
    }
};
