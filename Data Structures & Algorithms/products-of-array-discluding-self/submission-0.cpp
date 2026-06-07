class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,1), leftProd(n), rightProd(n);

        for(int i=0;i<n;++i)
        {
            leftProd[i] = nums[i];

            rightProd[n-i-1] = nums[n-i-1];
            if(i)
            {
                leftProd[i] *=leftProd[i-1];
                rightProd[n-1-i]*= rightProd[n-i];
            }
        }
        for(int i=0;i<n;++i)
        {
            if(i+1 < n)
                result[i] = rightProd[i+1];
            if(i-1 >=0)
                result[i]*=leftProd[i-1];
        }

        return result;
    }
};
