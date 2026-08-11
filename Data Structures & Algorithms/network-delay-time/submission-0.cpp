class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        unordered_map <int, vector < pair<int, int> > > adjList;

        for(const auto & time: times)
        {
            adjList[time[0]].push_back({time[1], time[2]});
        }

        priority_queue < pair<int, int>, vector < pair<int, int>>, greater<>> minHeap;

        minHeap.push({0,k});
        int t = 0;

        unordered_set <int> visited;

        while(!minHeap.empty())
        {
            auto cur = minHeap.top();
            minHeap.pop();
            int w1 = cur.first;
            int d1 = cur.second;

            if(visited.count(d1))
            {
                continue;
            }

            visited.insert(d1);
            t = w1;

            if(adjList.count(d1))
            {
                for(const auto & next: adjList[d1])
                {
                    int w2 = next.second;
                    int d2 = next.first;

                    if(!visited.count(d2))
                    {
                        minHeap.push({w1+w2, d2});
                    } 
                }
            }

        }

        return visited.size() == n ? t : -1;
        
    }
};
