class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int speed = 1;

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l < r)
        {
            int mid = l + (r-l)/2;

            if(canFinish(piles, mid, h))
            r = mid;
            else
            l = mid+1;
        }

        return l;
        
    }


    bool canFinish(vector<int>& piles, int speed, int h)
    {
        long long hours = 0;

        for(int p : piles)
        {
            hours += (p + speed -1)/speed;
        }
        return hours <= h;
    }
};
