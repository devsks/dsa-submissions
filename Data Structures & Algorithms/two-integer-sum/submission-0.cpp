class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        for(int i=0;i<nums.size();++i)
        {
            int num = nums[i];
            int need = target-num;
            if(seen[need])
            {
                return {seen[need]-1,i};
            }
            seen[num]=i+1;
        }
        return {};
    }
};
