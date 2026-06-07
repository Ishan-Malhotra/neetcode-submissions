class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        unordered_set <int> inventory;

        for(int num : nums)
        {
            if(inventory.count(num))
            {
                return num;
            }
            else
            inventory.insert(num);
        }
    }
};
