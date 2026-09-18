class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_set <int> list;

        vector<int> res;

        for(int i : nums)
        {
            if(list.count(i))
            {
                continue; 
            }
            else
            {
                list.insert(i);
                res.push_back(i);
            }
        }

        nums = res;
        return res.size();
    }
};