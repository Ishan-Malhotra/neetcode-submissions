class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        unordered_set <int> list;

        for(int num : nums)
        {
            if(list.count(num))
            return true;
        
        list.insert(num);
        }

        return false;

        
    }
};