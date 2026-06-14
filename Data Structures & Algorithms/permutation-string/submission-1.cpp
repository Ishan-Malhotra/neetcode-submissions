class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        //we create two hash maps: count1 and count2 

        unordered_map <char, int> count1;
        

        //every character in s1 should be in s2
        for(char c: s1)
        {
            count1[c]++;
        }

        //so count1 is a frequeny map right now

        //need1 is the number of unique characters in s1 whose counts must match
        int need = count1.size();

        for(int i = 0; i < s2.size(); i++)
        {
            unordered_map <char, int> count2;
            int cur = 0;

            for(int j = i; j < s2.length(); j++)
            {
                char c = s2[j];
                count2[c]++;

                if(count1[c] < count2[c])
                break;

                if(count1[c] == count2[c])
                cur++;

                if(cur == need)
                return true;
            }
        }  
        return false; 
    }


};
