class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int zeroFound = -1;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==0)
                zeroFound = i;
            if(abs(nums[i]) < n)
            {

                nums[abs(nums[i])]*=-1;
            }
        }

        if(zeroFound==-1)
            return 0;
        if(zeroFound!=0)
        {

        nums[zeroFound ] = n+2;
            for(int i=0;i<nums.size();++i)
            {
                if(abs(nums[i]) < n &&nums[abs(nums[i])]==n+2 )
                {

                    nums[abs(nums[i])]*=-1;
                    break;
                }
            }

        }
        for(int i=0;i<nums.size();++i)
        {
          //  cout<<nums[i]<<" ";
            if(nums[i]>0)
            {
                return i;
            }
        }
        return nums.size();
    }
};
