class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_set <int> list;

        for(int n:nums)
        {
            if(list.count(n))
                return true;
            
            else
            list.insert(n);
        }
        return false;
        
    }
};