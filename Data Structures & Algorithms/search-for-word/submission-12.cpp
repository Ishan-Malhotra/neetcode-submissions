class Solution {
public:

    int ROWS;
    int COLS;

    set < pair<int, int>> path;

    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};


    bool exist(vector<vector<char>>& board, string word) 
    {
        ROWS = board.size();
        COLS = board[0].size();

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(board[r][c] == word[0])
                {
                    if(dfs(board, word,0, r, c))
                    return true;
                }
            }
        }

        return false;
        
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int r, int c)
    {
        if(i == word.size())
        return true;

        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || word[i] != board[r][c] || path.count({r,c}))
        {
            return false;
        }

        //now word[i] == board[r][c]
        path.insert({r,c});
        bool res = false;

        for(int j = 0; j < 4; j++)
        {
            int nr = r + dirs[j][0];
            int nc = c + dirs[j][1];

            if(dfs(board, word, i+1, nr, nc))
            res = true;
        }

        path.erase({r,c});
        return res;

    }


};
