class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        queue < pair<int, int> > aq;
        queue < pair<int, int> > pq;

        vector<vector<bool>> pacific (ROWS, vector<bool> (COLS, false));
        vector<vector<bool>> atlantic (ROWS, vector<bool> (COLS, false));

        //mark the corners accessible

        for(int r = 0; r < ROWS; r++)
        {
            pq.push({r,0});
            pacific[r][0] = true;
            aq.push({r, COLS-1});
            atlantic[r][COLS-1] = true;
        }

        for(int c = 0; c < COLS; c++)
        {
            pq.push({0,c});
            pacific[0][c] = true;
            aq.push({ROWS-1, c});
            atlantic[ROWS-1][c] = true;
        }

        bfs(pq, pacific, heights);
        bfs(aq, atlantic, heights);

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

    void bfs(queue<pair<int,int>> &q, vector<vector<bool>> &ocean, vector<vector<int>>&heights)
    {
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty())
        {
            auto node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = row + dir[i][0];
                int nc = col + dir[i][1];

                if(nr >= 0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[row][col])
                {
                    ocean[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }
};
