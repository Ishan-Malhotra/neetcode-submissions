class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int res = 0;

        queue <pair <int,int> > q;
        int freshCount = 0;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == 2)
                {
                    q.push({r,c});
                }
                else if(grid[r][c] == 1)
                {
                    freshCount++;
                }
            }
        }

        if(freshCount == 0)
        return 0;


        int minutes = 0;
        int dir [4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty() && freshCount > 0)
        {
            int qSize = q.size();

            //process all rotting in the current minute

            for(int i = 0; i < qSize; i++)
            {

            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            for(int d = 0; d < 4; d++)
            {
                int nr = row + dir[d][0];
                int nc = col + dir[d][1];

                if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid[nr][nc] == 1 )
                {
                    q.push({nr,nc});
                    grid[nr][nc] = 2;
                    freshCount--;
                }
            }

            }
            minutes++;

        }
        return freshCount == 0 ? minutes : -1;
        
    }
};
