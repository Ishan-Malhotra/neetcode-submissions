class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();

        if(n == 0) return 0;

        vector<int> maxL(n, 0);
        vector<int> maxR (n,0);

        maxL[0] = height[0];
        maxR[n-1] = height[n-1];

        for(int i = 1; i < n; i++)
        {
            maxL[i] = max(height[i], maxL[i-1]);
        }

        for(int i = n-2; i >= 0; i--)
        {
            maxR[i] = max(height[i], maxR[i+1]);
        }


        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            int water = min(maxL[i], maxR[i]) - height[i];
            if(water >= 0)
            {
                sum += water;
            }
        }
        return sum;

        
    }
};
