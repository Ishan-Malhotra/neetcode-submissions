class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) 
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue < pair<int, int>> q;

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

        //now we have location of all the gates

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            for(int i = 0; i < 4; i++)
            {
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];

                if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == INT_MAX)
                {
                grid[nr][nc] = grid[row][col] + 1;
                q.push({nr,nc});
                }
           }
        }
    }
};
