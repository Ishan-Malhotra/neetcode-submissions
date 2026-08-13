class Solution {
public:

    bool dfs(int node, int parent, vector<bool> &visited, vector<vector<int>> &adjList)
    {
        //return true if you find a cycle else return false
        if(visited[node])
        return true;

        visited[node] = true;

        for(int nei: adjList[node])
        {
            if(nei == parent)
            continue;

            if(dfs(nei, node, visited, adjList))
            {
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        vector< vector<int> > adjList (n+1);
        

        for(auto & edge: edges)
        {
            int u = edge[0];
            int v = edge[1];
            vector<bool> visited (n+1,false);

            adjList[u].push_back(v);
            adjList[v].push_back(u);

            if(dfs(u, -1, visited, adjList))
            {
                return {u,v};
            }
        }

        return {};
    }
};
