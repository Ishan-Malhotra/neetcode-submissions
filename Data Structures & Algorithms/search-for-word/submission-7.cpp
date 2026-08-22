class Solution {
public:

    int ROWS;
    int COLS;

    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    
    string res;

    bool exist(vector<vector<char>>&board, string word) 
    {
        int ROWS = board.size();
        int COLS = board[0].size();
        int n = word.size();


        for(int r = 0; r < ROWS; r++)
        {
            for(int c = 0; c < COLS; c++)
            {
                if(board[r][c] == word[0])
                {
                    if(bfs(board, word, r, c))
                    return true;
                }

            }
        }

        return false;
    }

    bool bfs(vector<vector<char>>& board, string &word, int r, int c)
    {
        if(word.size() == 1)
        return true;

        int ROWS = board.size();
        int COLS = board[0].size();

        //q stores {row, col, index_in_word, list of visited coordinates}
        queue<tuple<int, int, int, vector<pair<int, int>> > >q;
        q.push({r,c,1,{{r,c}}});

        while(!q.empty())
        {
           auto [row, col, s, path] = q.front();
           q.pop();

            
            //explore all four directions
            for(int i = 0; i < 4; i++)
            {
                int nr = row + dirs[i][0];
                int nc = col + dirs[i][1];

            
                if(nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && board[nr][nc] == word[s])
                {
                    //check if we have already visited
                    bool already_visited = false;

                    for(auto & p: path)
                    {
                        if(p.first == nr && p.second == nc)
                        {
                            already_visited = true;
                            break;
                        }
                    }

                    if(!already_visited)
                    {
                        if(s+1 == word.size())
                        return true;

                        vector<pair<int, int>> new_path = path;
                        new_path.push_back({nr,nc});

                        q.push({nr,nc,s+1, new_path});
                    }

                   
                }
                
            }


        }
        return false;

    }
};
