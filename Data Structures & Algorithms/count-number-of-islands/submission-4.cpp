class Solution 
{
public:
    int dirs [4][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    int ROWS;
    int COLS;

    int numIslands(vector<vector<char>>& grid) 
    {
        ROWS = grid.size();
        COLS = grid[0].size();
        int count = 0;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == '1')
                {
                    bfs(grid, r, c);
                    count++;
                }
            }
        }

        return count;
    }


    void bfs(vector<vector<char>>& grid, int r, int c)
    {
        queue <pair <int, int>> q;
        grid[r][c] = '0';
        q.push({r,c});
        
        while(!q.empty())
        {
        auto node = q.front();
        int row = node.first;
        int col = node.second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nr = row + dirs[i][0];
            int nc = col + dirs[i][1];

            if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == '1')
            {
                q.push({nr,nc});
                grid[nr][nc] = '0';
            }
        }

        }
    }
};
