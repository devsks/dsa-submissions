class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int canReach = 0;
        for(int i=0;canReach < n-1 && i<n;++i)
        {
            if(i > canReach)
                return false;
            canReach = max(canReach,i+nums[i]);
        }

        return true;
    }
};
