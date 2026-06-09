class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int totalXor=0, actualXor=0;
        for(int i=0;i<=nums.size();++i)
            totalXor^=i;
        for(int &num:nums)
            actualXor^=num;
        return totalXor^actualXor;
    }
};
