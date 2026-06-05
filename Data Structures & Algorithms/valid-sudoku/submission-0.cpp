class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //check for rows

        for(int row = 0; row < 9; row++)
        {
            unordered_set <int> seen;

            for(int i = 0; i < 9; i++)
            {
                if(board[row][i] == '.')
                continue;

                if (seen.count(board[row][i]))
                {
                    return false;
                }
                else
                {
                    seen.insert(board[row][i]);
                }
            }
        }

        //check for columns

        for(int column = 0; column < 9; column++)
        {
            unordered_set <int> seen;

            for(int i = 0; i < 9; i++)
            {
               if(board[i][column] == '.'){
               continue;
               }

               if(seen.count(board[i][column]))
               {
                return false;
               }
               else
               {
                seen.insert(board[i][column]);
               }
            }
        }

        //check for sub-boxes

        for(int box = 0; box < 9; box++)
        {
            unordered_set <int> seen;
            for(int i = 0; i < 3; i++)
            {
                
                for(int j = 0; j < 3; j++)
                {
                    int row = (box / 3) * 3 + i;
                    int column = (box % 3) * 3 + j;

                    if(board[row][column] == '.')
                    continue;

                    if(seen.count(board[row][column]))
                    {
                        return false;
                    }
                    else
                    {
                    seen.insert(board[row][column]);
                    }
                }
            }
        }

        return true;
        
    }
};
