class Solution {
public:

    vector<int> cache;

    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        cache.resize(n, -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int i)
    {
        int n = cost.size();

        if(i > n-1)
        return 0;

        if(cache[i] != -1)
        return cache[i];

        cache[i] = cost[i] + min(dfs(cost, i+1), dfs(cost, i+2));
        return cache[i];

    }
};
