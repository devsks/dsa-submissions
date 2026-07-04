class Solution {
public:

    int search(vector<int>& nums, int target) {
        int low =0, high = nums.size();
        int index =-1;
        while(low < high)
        {
            int mid = (low+high)>>1;

            if(nums[mid]==target)
                return mid;
            if(nums[low] <= nums[mid])
            {
                if(target >= nums[low] && target <= nums[mid])
                {
                    high = mid;
                }
                else
                    low = mid+1;
            }
            else
            {
                 if(target > nums[mid] && target <= nums[high-1])
                {
                    low = mid+1;
                }
                else
                    high = mid;
            }
        }

        return index;
    }
};

/*

3 4 5 6 1 2
low=0, high = 6
mid = 3
*/
