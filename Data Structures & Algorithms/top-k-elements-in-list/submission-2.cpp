class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> fq;
        vector<int> fqSort;
        vector<int> res;
        for(int num :nums)
        {
            ++fq[num];
        }
        for(auto &it : fq)
        {
            fqSort.push_back(it.first);
        }
        sort(fqSort.begin(),fqSort.end(),[&](int a, int b)
        {
            if(fq[a]==fq[b])
            {
                return a <b;
            }
            else
            {
                return fq[a] > fq[b];
            }
        });
        int i=0;
        while(k>0)
        {
            res.push_back(fqSort[i]);
            --k;
            ++i;
        }
        return res;
    }
};
