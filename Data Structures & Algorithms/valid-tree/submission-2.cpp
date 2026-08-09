class Solution {
public:

    unordered_map <int, vector<int>> adjList;
    unordered_set <int> visited;

    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if(edges.size() != n-1)
        return false;


        // a tree does not have cycles
        for(int i = 0; i < n; i++)
        {
            adjList[i] = {};
        }

        for(const auto & edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        //adj list filled

        if(!dfs(0,-1))
        return false;

        return visited.size() == n;
    }

    bool dfs(int node, int parent)
    {
        visited.insert(node);

        for(int child : adjList[node])
        {
            if(child == parent)
            continue;

            if(visited.count(child) || !dfs(child,node))
            {
                return false;
            }
        }

        return true;

    }
};
