class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ones(n+1,0);
        for(int i=1;i<=n;++i)
        {
            int count =0, num =i;
            while(num>0)
            {
                if(num&1)
                ++count;
                num>>=1;
            }
            ones[i]=count;
        }

        return ones;
    }
};
