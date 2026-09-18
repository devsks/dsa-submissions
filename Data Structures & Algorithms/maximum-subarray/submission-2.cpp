class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int maxSum = curSum;
        int minValSoFar = nums[0];
 
        for(int i = 1; i < nums.size(); ++i)
        {
            curSum += nums[i];
            maxSum = max({maxSum, curSum, curSum - minValSoFar}); 
            minValSoFar = min(minValSoFar,curSum);
        }

        return maxSum;
    }
};
