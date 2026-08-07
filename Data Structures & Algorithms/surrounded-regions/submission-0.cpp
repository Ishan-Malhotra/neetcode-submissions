class Solution {
public:

    int ROWS;
    int COLS;

    int dir[4][2] = {{1,0},{-1, 0},{0,1},{0,-1}};

    void solve(vector<vector<char>>& board) 
    {
        ROWS = board.size();
        COLS = board[0].size();

        //run a bfs on the border
        capture(board);

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(board[r][c] == 'O')
                {
                    board[r][c] = 'X';
                }
                else if(board[r][c] == 't')
                {
                    board[r][c] = 'O';
                }
            }
        }

        
    }

    void capture(vector<vector<char>> &board)
    {
        queue<pair<int,int>> q;

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(((r == 0) || (r == ROWS-1) || (c == 0) || (c == COLS-1)) && (board[r][c] == 'O') )
                {
                    board[r][c] = 't';
                    q.push({r,c});
                }
            }
        }

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

                if(nr >=0 && nr < ROWS && nc >= 0 && nc < COLS && board[nr][nc] == 'O')
                {
                    board[nr][nc] = 't';
                    q.push({nr,nc});
                }

            }
            

        }
    }
};
