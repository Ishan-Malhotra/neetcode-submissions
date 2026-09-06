class Solution {
public:

    vector<int> cache;

    int climbStairs(int n) 
    {
        cache.resize(n+1, -1);
        return dfs(0, n);
    }

    int dfs(int i, int n)
    {
        if(i > n)
        return 0;

        if(i == n)
        return 1;

        if(cache[i] != -1)
        return cache[i];

        cache[i] = dfs(i+1, n) + dfs(i+2, n);
        return cache[i];
    }
};
