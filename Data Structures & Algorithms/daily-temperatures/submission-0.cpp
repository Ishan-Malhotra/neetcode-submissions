class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {

        int temp;
        int count = 0;

        vector <int> ans;

        for(int i = 0; i < temperatures.size(); i++)
        {
            temp = temperatures[i];

            for(int j = i; j < temperatures.size(); j++) 
            {
                if (temperatures[j] > temp)
                {
                count = j - i;
                break;
                }

                else
                count = 0;
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};

// ans.push_back(count);
