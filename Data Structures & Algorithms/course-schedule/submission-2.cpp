class Solution {
public:

    unordered_map <int, vector<int>> adjList;
    unordered_set <int> visited;
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        for(const auto & preq: prerequisites)
        {
            adjList[preq[0]].push_back(preq[1]);
        }

        for(int c = 0; c < numCourses; c++)
        {
            if(!dfs(c)) return false;
        }
        return true;
    }


    bool dfs(int c)
    {
        if(visited.count(c))
        return false;

        if(adjList[c].empty()) //no prereqs required
        {
            return true;
        }

        visited.insert(c);

        //if prereq required, visit each prereq
        for(int pre: adjList[c])
        {
            if(!dfs(pre)) return false;
            
        }

        visited.erase(c);
        adjList[c] = {};
        return true;
    }
};
