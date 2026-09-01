class Solution {
public:

    vector<int> cache;

    int climbStairs(int n) 
    {
        cache.resize(n+1, -1);
        return dfs(n);
    }

    int dfs(int i)
    {
        if(cache[i] != -1)
        return cache[i];

        if(i == 1)
        return 1;

        if(i == 2)
        return 2;

        cache[i] = dfs(i-1) + dfs(i-2);
        return cache[i];
        
    }
};
