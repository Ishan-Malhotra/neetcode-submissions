class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if(edges.size() > n-1)
        return false;

        vector < vector<int> > adj(n);

        //filling the adjacency list
        for(const auto & edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visit(n, false);
        int visited = 0;

        if(!dfs(0, -1, visit, adj, visited))
        return false;

        return visited == n;
    }

    bool dfs(int node, int parent, vector<bool> &visit, vector <vector<int>> &adj, int &visited)
    {
        //cycle detector
        if(visit[node] == true)
        return false;

        visit[node] = true;
        visited++;

        //lets go to its neighbours

        for(int nei: adj[node])
        {
            if(nei == parent)
            continue;

            if(!dfs(nei, node, visit, adj, visited))
            return false;
        }
        return true;
    }
};
