class Solution {
public:
    int ROWS;
    int COLS;
    set<pair<int,int>> path;

    bool exist(vector<vector<char>>& board, string word) 
    {
        ROWS = board.size();
        COLS = board[0].size();
        
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(dfs(0,i,j, board, word))
                return true;
            }
        }
         return false;
        
    }

    bool dfs(int i, int r, int c, vector<vector<char>>& board, string word)
    {
        if(i == word.size())
        return true;

        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || word[i] != board[r][c]|| path.count({r,c}) )
        return false;

        //here word[i] = board[r][c]
        path.insert({r,c});
        bool res = (dfs(i+1,r+1,c,board, word) || dfs(i+1,r-1,c,board, word) || dfs(i+1,r,c+1,board, word)||dfs(i+1,r,c-1,board, word));
        
        path.erase({r,c});
        return res;
    }
};
