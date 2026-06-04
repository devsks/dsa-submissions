class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> unq;
        for(int &num : nums)
            unq.insert(num);
        return unq.size()!=nums.size();
    }
};