class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int l = 0;
        int r = heights.size() - 1;

        int area = 0;
        int maxarea = 0;

        while(l < r)
        {
           area = min(heights [l] , heights[r]) * (r - l);
           maxarea = max(area, maxarea);

           if(heights[l] < heights [r])
           {
            l++;
           }
           else
           r--;
           
        }
        return maxarea;

    }
};
