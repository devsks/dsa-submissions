class Solution {
public:
    int rob(vector<int>& nums) {
        int robFrom1 =nums[0];
        int robFrom0 =nums[0];
        int n_1=0,n_2=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            int cur_loot = max({nums[i]+n_2,n_1});
            n_2 = n_1;
            n_1 = cur_loot;
            
        }
        robFrom0 =  max(robFrom0,n_1);
        n_1=n_2=0;
        for(int i=1;i<nums.size();++i)
        {

            int cur_loot = max({nums[i]+n_2,n_1});
            n_2 = n_1;
            n_1 = cur_loot;

        }

        robFrom1 =  max(robFrom1,n_1);
        return max(robFrom1,robFrom0);   
    }
};
