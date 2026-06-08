class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq;
        for(int &num : nums)
            seq.insert(num);

        int maxLen =0;
        for(int &num: nums)
        {
            if(seq.find(num-1)!= seq.end())
                continue;
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
