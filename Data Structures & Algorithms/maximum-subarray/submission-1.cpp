class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> curSum(nums.size());
        curSum[0] = nums[0];
        int maxSum = nums[0];
        set<int> minVals;
        minVals.insert(nums[0]);
        for(int i=1;i<nums.size();++i)
        {
            curSum[i] = nums[i]+curSum[i-1];
            maxSum = max(maxSum,curSum[i]);
            
            int total = curSum[i]- *minVals.begin();
            maxSum = max(maxSum, total);
            
            minVals.insert(curSum[i]);
        }

        return maxSum;
    }
};
