class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<int> distance;
        int n = points[0].size();

        priority_queue < pair<double, vector<int> >> maxHeap;

        for(auto & point: points)
        {
            int x = point[0];
            int y = point[1];

            double a = (x * x) + (y * y);
            double dis = sqrt(a);

            distance.push_back(dis);
            maxHeap.push({dis, point});
        }

        while(maxHeap.size() > k)
        {
            maxHeap.pop();
        }

        vector<vector<int>> res;

        while(!maxHeap.empty())
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
