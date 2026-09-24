class Solution {
public:
    int loot(vector<int>&nums, int start, int end)
    {
        int n_1=0,n_2=0;
        for(int i=start;i<end;++i)
        {
            int cur_loot = max({nums[i]+n_2,n_1});
            n_2 = n_1;
            n_1 = cur_loot;
            
        }
        return n_1;
    }
    int rob(vector<int>& nums) {
        int robFrom1 =nums[0];
        int robFrom0 =nums[0];
        robFrom0 =  max(robFrom0,loot(nums,0,nums.size()-1));
        robFrom1 =  max(robFrom1,loot(nums,1,nums.size()));
        return max(robFrom1,robFrom0);   
    }
};
