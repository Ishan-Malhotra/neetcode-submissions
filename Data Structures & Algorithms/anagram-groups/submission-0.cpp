class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map <string, vector <string>> res; //empty map

        for(const auto & s: strs)
        {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());

            res[sortedS].push_back(s);
        }

        //we must return a list of lists

        vector<vector<string>> result;

        for(auto & pair: res)
        {
            result.push_back(pair.second);
        }

        return result;


    }
};
