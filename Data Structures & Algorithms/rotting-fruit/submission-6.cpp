class Solution {
public:
    int dirs [4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue < pair<int, int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int fresh = 0;
        int time = 0;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(grid[r][c] == 1)
                {
                    fresh++;
                }
                else if(grid[r][c] == 2)
                {
                    q.push({r,c});
                }
            }
        }

        cout << fresh << endl ;


        while(!q.empty() && fresh>0)
        {
            int sz = q.size();

            for(int i = 0; i < sz; i++)
            {

            
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            for(int i = 0; i < 4; i++)
            {
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];

                if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1)
                {
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                    fresh--;
                }
            }
            

            }
            time++;
        }

        return fresh == 0 ? time : -1;

        
    }
};
