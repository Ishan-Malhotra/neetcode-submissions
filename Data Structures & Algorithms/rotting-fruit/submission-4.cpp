class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue < pair<int, int>> q; 
        int fresh = 0;

        

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
                    fresh++;
                }
            }
        }

        //so q  = all rotten cells
        //fresh = no of fresh fruits
        //lets run dfs together from all rotten cells

        int minutes = 0;
        int dirs [4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}};
        

        while(!q.empty() && fresh > 0)
        {
            int size = q.size();

            for(int j = 0; j < size; j++)
            {
                auto node = q.front();
                int r = node.first;
                int c = node.second;
                q.pop();

                for(int i = 0; i < 4; i++)
                {
                int row = r + dirs[i][0];
                int col = c + dirs[i][1];

                if(row >= 0 && row < ROWS && col >= 0 && col < COLS && grid[row][col] == 1)
                {
                    grid[row][col] = 2;
                    fresh--;
                    q.push({row,col});
                }
            

                }}

            minutes++;  
             
        
        }

        return fresh == 0 ? minutes : -1;
    }
};
