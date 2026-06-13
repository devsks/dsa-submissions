class Solution {
public:
    vector<vector<int>> twoSum(vector<int>&nums, int start, int target)
    {
        vector<vector<int>> res;
        int low = start, high = nums.size()-1;
        while(low < high)
        {
            if(nums[low]+nums[high] == target)
            {
                res.push_back({nums[low],nums[high]});
                ++low;
                --high;

                while(low < high && nums[low]==nums[low-1])
                    ++low;
                
                while(high> low && nums[high]==nums[high+1])
                    --high;
            }
            else if(nums[low]+nums[high] < target)
            {
                ++low;
            }
            else
                --high;
        }
        return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // O(nlogn)
        sort(nums.begin(),nums.end());

        vector<vector<int>> res;

        for(int i=0;i<nums.size();++i)
        {
            if(i && nums[i]==nums[i-1])
                continue;
            vector< vector<int>> twoSumRes = twoSum(nums, i+1, -nums[i]);
            for(vector<int> inds : twoSumRes)
            {
                inds.push_back(nums[i]);
                res.push_back(inds);
            }
        }

        return res;
    }
};
