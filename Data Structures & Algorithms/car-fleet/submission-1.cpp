class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size(); 

        vector <pair<int, int>> pair(n);

        for(int i = 0; i < position.size(); i++)
        {
            pair[i].first = position[i];
            pair[i].second = speed[i];
        }

        sort(pair.rbegin(), pair.rend());

        vector<double> stack;

        for(int i = 0; i < n; i++)
        {
            double time = (double)(target - pair[i].first)/pair[i].second;
            stack.push_back(time);
            
            //current car's time = stack.back();
            //time of the fleet ahead of it = stack[stack.size() - 2]
            if(stack.size() >= 2 && stack.back() <= stack[stack.size() -2])
            {
                stack.pop_back();
            }


        }
        return stack.size();
        
    }
};
