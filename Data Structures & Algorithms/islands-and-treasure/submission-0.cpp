class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue < pair <int, int>> q;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == 0)
                {
                    q.push({r,c});
                }
            }
        }

        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //check the neighbours

            for(int i = 0; i < 4; i++)
            {
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];

                if(nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != INT_MAX)
                {
                    continue;
                }
                grid[nr][nc] = grid[row][col] + 1;
                q.push({nr,nc});
            }
        }
        
    }
};
