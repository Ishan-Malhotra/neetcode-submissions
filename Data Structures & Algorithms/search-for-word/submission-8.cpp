class Solution {
public:

    int ROWS;
    int COLS;
    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    set <pair<int, int>> path;

    bool exist(vector<vector<char>>& board, string word) 
    {
        ROWS = board.size();
        COLS = board[0].size();

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(dfs(board, word, r, c, 0))
                return true;
            }
        }
        return false;
        
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i)
    {
        if(i == word.size())
        return true;

        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != word[i] || path.count({r,c}))
        {
            return false;
        }

        path.insert({r,c});
        bool found = false;

        for(int j = 0; j < 4; j++)
        {
            int nr = r + dirs[j][0];
            int nc = c + dirs[j][1];

            if( dfs(board, word, nr, nc, i+1))
            {
                found = true;
                break;
            }
        }
        path.erase({r,c});
        return found;
    }
};
