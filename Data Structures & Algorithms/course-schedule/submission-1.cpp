class Solution {
public:

    unordered_map <int, vector<int>> preMap;
    unordered_set <int> visited;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        for(int i = 0; i < numCourses; i++)
        {
            preMap[i] = {};
        }

        for(const auto& prereq : prerequisites)
        {
            preMap[prereq[0]].push_back(prereq[1]); 
        }

        for(int c = 0; c < numCourses; c++)
        {
            if(!dfs(c))
            {
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs)
    {
        //we found a circle
        if(visited.count(crs))
        {
        return false;
        }

        //no prequisites required
        if(preMap[crs].empty())
        {
            return true;
        }

        //time to run dfs
        visited.insert(crs);

        for(int pre: preMap[crs])
        {
            if(!dfs(pre))
            {
                return false;
            }
        }

        visited.erase(crs);
        preMap[crs] = {};
        return true;
    }
};
