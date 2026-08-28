class Solution {
public:
    int maxArea(vector<int>& heights) 
    {
        int l = 0;
        int r = heights.size() -1;

        int area;
        int maxarea = 0;

        while(l < r)
        {
            area = (r-l) * min(heights[l], heights[r]);
            maxarea = max(area, maxarea);


            if(heights[r] < heights[l])
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return maxarea;

    }
};
