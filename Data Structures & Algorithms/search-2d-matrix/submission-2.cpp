class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        //because verything is sorted, we can say this is one huge sorted array
        //size = rows * cols

        int rows = matrix.size();
        int col = matrix[0].size();

        int top = 0;
        int bottom = rows - 1;

        int row = (top + bottom)/2;

    
        while( top <= bottom )
        {
            row =  (top + bottom) / 2 ;

            //if target is greater than last element of this row: move down
            //if target is lesser than the first element of this row: move up
            //otherwise we are in the correct row

            if (target > matrix[row][col - 1]) 
            {
                top = row + 1;
            }

            else if ( target < matrix[row][0])
            {
                bottom = row - 1;
            }

            else
            {
               break; 
            }
        }

        if(top > bottom)
        return false;

        //so now we are in the correct row, lets run a normal binary search

        int left = 0;
        int right = col - 1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(matrix[row][mid] == target)
            {
                return true;
            }
            else if (matrix[row][mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return false;

        
    }
};
