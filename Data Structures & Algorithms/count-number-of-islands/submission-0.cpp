class Solution {
public:

    int ROWS;
    int COLS;
    int islands;

    //adjacent islands are one island

    int numIslands(vector<vector<char>>& grid) 
    {
        ROWS = grid.size();
        COLS = grid[0].size();

        islands = 0;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == '1')
                {
                    //sink it and its adjacent 1s
                    dfs(grid, r, c);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(vector<vector<char>> &grid, int r, int c)
    {
        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == '0')
        {
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);

    }
};
