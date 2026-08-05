class Solution {
public:

    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        if(heights.empty() || heights[0].empty())
        {
            return {};
        }

        int ROWS = heights.size();
        int COLS = heights[0].size();

        //make boolean grids to track reachable cells
        vector <vector<bool>>  pacific(ROWS, vector<bool> (COLS, false));
        vector <vector<bool>> atlantic (ROWS, vector<bool> (COLS, false));

        //queue for BFS
        queue < pair<int, int> > pacQ;
        queue < pair<int, int> > atlQ;

        //seed the ocean borders, mark them as visited

        for(int r = 0; r < ROWS; r++)
        {
            pacQ.push({r,0});
            pacific[r][0] = true;

            atlQ.push({r, COLS - 1});
            atlantic[r][COLS - 1] = true;
        }

        for(int c = 0; c < COLS; c++)
        {
            pacQ.push({0,c});
            pacific[0][c] = true;

            atlQ.push({ROWS-1,c});
            atlantic[ROWS-1][c] = true;
        }

        bfs(pacQ, pacific, heights);
        bfs(atlQ, atlantic, heights);

        vector<vector<int>> res;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(pacific[r][c] && atlantic[r][c])
                {
                    res.push_back({r,c});
                }
            }
        }
        return res;




        
    }

   

    void bfs(queue<pair<int, int>> &q, vector<vector<bool>> &ocean, vector<vector<int>> & heights)
    {
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

            for(int i = 0; i < 4; i++)
            {
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];

                if(nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[row][col])
                {
                    ocean[nr][nc] = true;
                    q.push({nr,nc});
                }

            }
        }
    }
};
