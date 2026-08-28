class Solution {
public:

    int ROWS;
    int COLS;
    vector<vector<bool>> visited;

    int dirs[4][2] = {{1,0}, {-1,0}, {0,1},{0,-1}};

    bool exist(vector<vector<char>>& board, string word) 
    {
        ROWS = board.size();
        COLS = board[0].size();

        visited.resize(ROWS, vector<bool> (COLS, false));
        
        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(dfs(board, word, 0, r, c))
                return true;
            }
        }
        return false;
    }


    bool dfs(vector<vector<char>>& board, string word, int i, int r, int c)
    {
        if(i == word.size())
        return true;

        if(r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != word[i] || visited[r][c] == true)
        {
            return false;
        }
        visited[r][c] = true;

        for(int j = 0; j < 4; j++)
        {
            int nr = r + dirs[j][0];
            int nc = c + dirs[j][1];

            if(dfs(board, word,i+1,nr,nc))
            return true;
        }

        visited[r][c] = false;
        return false;
        

    }
};
