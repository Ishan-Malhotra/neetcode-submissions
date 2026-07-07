class Solution {
public:
    vector<string> res;

    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno","pqrs","tuv" ,"wxyz"};

    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty())
        {
            return {};
        }
        
        dfs(0, "", digits);
        return res;
    }

    void dfs(int i, string cur, string &digits)
    {
        
        if(cur.size() == digits.size())
        {
            res.push_back(cur);
            return;
        }

        string chars = digitToChar[digits[i]-'0'];

        for(char c: chars)
        {
            dfs(i+1, cur + c , digits);
        }


    }
};
