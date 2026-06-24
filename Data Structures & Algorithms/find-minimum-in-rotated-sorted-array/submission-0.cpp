class Solution {
public:
    int findMin(vector<int> &nums) {
        int low =0, high = nums.size();

        int min_val = nums[0];
        while(low < high)
        {
            int mid = (low+high)>>1;

                min_val = min(min_val,nums[mid]);
            if(nums[mid] >= nums[low] && nums[mid] <= nums[high-1])
            {
                min_val = min(min_val,nums[low]);
                high = mid;
            }
            else if(nums[mid] <= nums[low])
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return min_val;
    }
};
