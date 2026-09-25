class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        int n = nums.size();
        vector<int> minProd(n),maxProd(n);
        int maxRes = INT_MIN;
        for(int i=0;i<n;++i)
        {
            if(i)
            {
                if(nums[i]>=0)
                {
                    minProd[i] = min(nums[i],minProd[i-1]*nums[i]);
                    maxProd[i] = max(nums[i],maxProd[i-1]*nums[i]);
                }
                else
                {

                    minProd[i] = min(nums[i],maxProd[i-1]*nums[i]);
                    maxProd[i] = max(nums[i],minProd[i-1]*nums[i]);
                }
            }
            else
            {
                minProd[i] = nums[i] < 0 ? nums[i] : 0;
                maxProd[i] = nums[i] < 0 ? 0 : nums[i];
            }
            //cout<<minProd[i]<<" "<<maxProd[i]<<endl;

            maxRes = max({maxRes,minProd[i],maxProd[i]});
        }
        return maxRes;
    }
};
/*
-2 1 -3 5
0  1  6 30
-2 -2 -3 -15
*/