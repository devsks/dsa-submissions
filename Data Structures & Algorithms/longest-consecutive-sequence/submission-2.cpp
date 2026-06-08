class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int> seq;
        for(int &num : nums)
            seq.insert(num);

        int maxLen =1;
        for(int &num: nums)
        {
            int currLen = 1;
            while(seq.count(num+1))
            {
                //seq.erase(num+1);
                currLen++;
                ++num;
            }
            maxLen = max(maxLen,currLen);
        }
        return maxLen;   
    }
};
