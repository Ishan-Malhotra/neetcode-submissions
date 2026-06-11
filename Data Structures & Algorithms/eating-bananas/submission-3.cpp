class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r; //to keep track of the best speed found so far

        while(l <= r)
        {
            int k = l + (r-l)/2;
            long long sum = 0;

            for(int pile : piles)
            {
                sum = sum + (pile+k-1)/k ;
            }

            if(sum <= h) //we are already fast, speed kam karo aur check karo
            {
                res = k;
                r = k - 1;
            }

            else // (sum > h) took too long, we need to eat faster
            //speed badhso
            {
                l = k + 1;
            }

        }
         
        return res;
    }
};
