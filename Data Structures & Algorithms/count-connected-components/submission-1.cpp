class Solution {
public:

    int res = 0;
    unordered_set <int> visited;

    void dfs(int u, vector<vector<int>> adjList)
    {
        visited.insert(u);

        for(int nei: adjList[u])
        {
            if(visited.find(nei) == visited.end())
            {
                dfs(nei, adjList);   
            } 
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adjList(n+1);

        for(auto & edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        for(int i = 0; i < n; i++)
        {
            if(visited.find(i) == visited.end())
            {
                dfs(i, adjList);
                res++;
            }
        }
        return res;
    }
};
