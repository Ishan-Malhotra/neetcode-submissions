class Solution {
public:

    int res = 0;
    unordered_set <int> visited;

    void dfs(int u, vector<vector<int>> &adjList)
    {
        
        visited.insert(u);
        cout << u << " ";

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
        

        for(auto & edge: edges)
        {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }


        //travel thru the adj list and push them in the set
        //if u are in set, fine, 
        //if u is not in set, res++

        

        for(int i = 0; i < n; i++)
        {
            if(visited.find(i) == visited.end())
            {
                //if you have already not visited this 
                dfs(i, adjList);
                res++;
            }
            
        }
        
        //if visited.size == n
        //we have visited all nodes

        return res;

    }
};
