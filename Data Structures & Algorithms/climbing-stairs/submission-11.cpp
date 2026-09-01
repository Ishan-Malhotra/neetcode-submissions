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
        if(i==1) return 1;
        if(i==2) return 2;
        if(cache[i] != -1) return cache[i];

        cache[i] = dfs(i-2)+dfs(i-1);
        return cache[i];


    }
};
