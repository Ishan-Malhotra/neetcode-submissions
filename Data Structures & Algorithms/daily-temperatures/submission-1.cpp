class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> res (n,0);

        stack< pair<int, int> > myStack;

        for(int i = 0; i < n; i++)
        {
            int t = temperatures[i]; //today's temp
            //i = today index

            while(!myStack.empty() && t > myStack.top().first)
            {
                res[myStack.top().second] = i - myStack.top().second;
                myStack.pop();
            }
            
            myStack.push({t, i});

        }
        return res;
    }
};
