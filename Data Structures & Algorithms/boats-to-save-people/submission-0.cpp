class Solution {
public:

    int numRescueBoats(vector<int>& people, int limit) 
    {
        int n = people.size();
        int count = 0;

        //pair the heaviest with the lightest person
        sort(people.begin(), people.end());
        
        int l = 0;
        int r = n-1;

        while(l <= r)
        {
            if(people[l] + people[r] <= limit)
            {
                count++;
                l++;
                r--;
            }
            else
            {
                count++; 
                r--;
            }
        }
        return count;

    }
};