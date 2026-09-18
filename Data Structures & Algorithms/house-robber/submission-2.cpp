class Solution {
public:
    int rob(vector<int>& nums) {
        int maxRob = nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        if(nums.size()==1)
            return maxRob;
        dp[1] = max(nums[0],nums[1]);
        maxRob = max(nums[0],nums[1]);
        for(int i=2;i<nums.size();++i)
        {
            dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
            maxRob = max(maxRob, dp[i]);
        }
        return maxRob;
    }
};
