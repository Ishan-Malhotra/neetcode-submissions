class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        //convert position and speed into a pair vector
        vector < pair <int, int> > pair;
        int n = position.size();

        for(int i = 0; i < n; i++)
        {
        pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());
        vector <double> list;

        for(auto& p: pair)
        {
            double time = (double)(target - p.first)/p.second;
            list.push_back(time);

            if (   (list.size() >= 2)   &&    (list.back() <= list[(list.size() - 2)] )     )
            {
                list.pop_back();
            }
        }

        return list.size();
        //now stack contains time taken by each car to reach target

    }

        
};
