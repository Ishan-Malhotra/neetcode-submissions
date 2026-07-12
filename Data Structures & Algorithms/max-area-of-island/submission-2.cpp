class Solution {
public:

    int ROWS;
    int COLS;

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        ROWS = grid.size();
        COLS = grid[0].size();
        int area = 0;
        int a = 0;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == 1)
                {
                    int cur = dfs(grid, r, c);
                    area = max(area, cur);
                }
            }
        }
        return area;
        
    }

    int dfs(vector<vector<int>> &grid, int r, int c)
    {
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == 0)
        {
            return 0 ; 
        }

        grid[r][c] = 0;

        int area = 1 + dfs(grid, r+1, c) + dfs(grid, r-1, c) + dfs(grid, r, c+1) + dfs(grid, r, c-1);
        return area;
    }

};
