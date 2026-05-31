class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> inventory;
        for (auto num : nums)
        {
            if(inventory.count(num))
                return true;
            else
            inventory.insert(num);
        }
        return false;
    }
};