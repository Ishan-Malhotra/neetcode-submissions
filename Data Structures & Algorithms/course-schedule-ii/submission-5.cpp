class Solution {
public:

    unordered_map <int, vector<int>> adjList;
    vector<int> state;
    //0 -> unvisited
    //1 -> visiting
    //2 -> visited
    vector<int> res;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {

        state.resize(numCourses, 0);

        for(const auto & prereq: prerequisites)
        {
            adjList[prereq[0]].push_back(prereq[1]);
        } 

        for(int c = 0; c < numCourses; c++)
        {
            if(state[c] == 0)
            {
                if(!dfs(c))
                {
                return {};
                }
            }
        }
        return res;
    }

    bool dfs(int c)
    {
        if(state[c] == 1) return false;
        if(state[c] == 2) return true;

        state[c] = 1;

        for(int pre : adjList[c])
        {
            if(!dfs(pre))
            {
                return false;
            }
        }

        //if control arrives here, that means its valid
        state[c] = 2;
        res.push_back(c);
        return true;
    }


};
