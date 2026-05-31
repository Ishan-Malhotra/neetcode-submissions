class Solution {
public:
    bool isAnagram(string s, string t) 
    {
     if(s.length() != t.length()){
     return false;
     }
     unordered_map <char,int> dictS;
     unordered_map <char,int> dictT;

     for(int i = 0; i < s.length();i++)
     {
        dictS[s[i]]++;
        dictT[t[i]]++;
     }
     return dictS == dictT;
    }
};
