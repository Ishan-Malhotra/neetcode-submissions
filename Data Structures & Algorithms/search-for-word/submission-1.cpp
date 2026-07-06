class Solution {
public:

    int ROWS;
    int COLS;
    set <pair<int, int>> path;

    

    bool exist(vector<vector<char>>& board, string word)
    {
        ROWS = board.size();
        COLS = board[0].size();

        //return dfs(0, 0, 0, board, word);

        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(dfs(0, r, c, board, word))
                return true;
            }
        }
        return false; 
    }

    //i is the count ki kitne words mil gaye

    bool dfs(int i, int r, int c, vector<vector<char>> &board, string word)
    {
        if(i == word.size())
        {
            return true;
        }

        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || word[i] != board[r][c] || path.count({r,c}) )
        {
            return false;
        }
        path.insert({r,c});

        //word[i] = board[r][c]
        bool res = (dfs(i+1, r+1, c, board, word) || dfs(i+1, r, c+1 , board, word) || dfs(i+1, r-1 , c, board, word)|| dfs(i+1, r, c-1, board, word));

        path.erase({r,c});
        return res;
    }
};
