class Solution {
public:

    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        queue < pair<int, int>> pq;
        queue < pair<int, int>> aq;

        vector < vector<bool> > pacific(ROWS, vector<bool>(COLS,false));
        vector < vector<bool> > atlantic(ROWS, vector<bool>(COLS,false));

        //make the corners accessible

        for(int r = 0; r < ROWS; r++)
        {
            pq.push({r,0});
            aq.push({r,COLS-1});

            pacific[r][0] = true;
            atlantic[r][COLS-1] = true;
        }

        for(int c = 0; c < COLS; c++)
        {
            pq.push({0,c});
            aq.push({ROWS-1,c});
            pacific[0][c] = true;
            atlantic[ROWS-1][c] = true;
        }

        dfs(heights, pq, pacific);
        dfs(heights, aq, atlantic);
        vector< vector<int>> res;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(pacific[r][c] == true && atlantic[r][c] == true)
                {
                    res.push_back({r,c});

                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& heights, queue <pair<int, int>> &q, vector<vector<bool>>& ocean)
    {
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;

            for(int i = 0; i < 4; i++)
            {
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];

                if(nr >= 0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() && heights[nr][nc] >= heights[row][col] && ocean[nr][nc] == false)
                {
                    //good pani flow
                    ocean[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
        
    }


};
