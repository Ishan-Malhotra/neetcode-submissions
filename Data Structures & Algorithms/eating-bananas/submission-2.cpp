class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int speed = 1; //banannas per hr
        while(true)
        {
            long long time = 0;

            for(int pile : piles)
            {
                time = time + (pile + speed - 1)/speed;
            }

            if(time <= h)
            {
                return speed;
            }

            speed++;
        }


        
    }
};
