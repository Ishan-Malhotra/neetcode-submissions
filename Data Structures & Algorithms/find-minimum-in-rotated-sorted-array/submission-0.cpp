class Solution {
public:
    int findMin(vector<int> &nums) 
    {
        set <int> s;

        for(int num : nums)
        {
            s.insert(num);
        }

        //all the elements are now sorted in ascending order in our sorted set
        //now we need to find the min element, which is the first element

        return *s.begin();
    
    }
};
