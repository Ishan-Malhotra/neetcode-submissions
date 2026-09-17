class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack < pair<int, int>> stack;

        for(int i = 0; i < n; i++)
        {
            int t = temperatures[i];

            while(!stack.empty() && t > stack.top().first)
            {
                auto temp = stack.top();
                stack.pop();
                res[temp.second] = i - temp.second;
            }
            stack.push({t,i});
        }
        return res;
       

    }
};
