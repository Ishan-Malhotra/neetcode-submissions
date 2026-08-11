class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map <string, vector<string> > list;

        for(const auto & str : strs)
        {
            string sortedS = str;
            sort(sortedS.begin(), sortedS.end());
            list[sortedS].push_back(str);
        }

        vector<vector<string>> res;

        for(const auto & str: list)
        {
            res.push_back(str.second);
        }
        return res;
    }
};
