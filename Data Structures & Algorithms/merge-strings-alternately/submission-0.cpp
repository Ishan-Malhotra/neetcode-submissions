class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int l1 = word1.size();
        int l2 = word2.size();

        string res = "";

        for(int i = 0; i < min(l1,l2); i++)
        {
            int l = word1[i];
            res.push_back(l);
            int r = word2[i];
            res.push_back(r);
        }

        int diff = abs(l1-l2);

        if(l1 > l2)
        {
            for(int i = l2; i < l1; i++)
            {
                res.push_back(word1[i]);
            }
        }
        else
        { 
            for(int i = l1; i < l2; i++)
            {
                res.push_back(word2[i]);
            }
        }

        return res;
        
    }
};