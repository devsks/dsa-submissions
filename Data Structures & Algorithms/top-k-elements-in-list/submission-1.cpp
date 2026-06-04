class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fq;
        vector<int> res;
        for(int num :nums)
        {
            ++fq[num];
        }
        sort(nums.begin(),nums.end(),[&](int a, int b)
        {
            if(fq[a]==fq[b])
            {
                return a <b;
            }
            else
            return fq[a] > fq[b];
        });
        int i=0;
        int prev = INT_MIN;
        while(k>0)
        {
            if(nums[i]!=prev)
            {
                res.push_back(nums[i]);
                --k;
            }
            prev = nums[i];
            ++i;

        }
        return res;
    }
};
