class Solution {
public:
    int trap(vector<int>& height) 
    {
        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[l];
        int rightMax = height[r];
        int sum = 0;

        while(l < r)
        {
            if(leftMax < rightMax)
            {
                l++;
                leftMax = max(leftMax, height[l]);
                sum = sum + leftMax - height[l];
            }

            else
            {
                r--;
                rightMax = max(rightMax, height[r]);
                sum = sum + rightMax - height[r];
            }
        }

        return sum;
        
    }
};
