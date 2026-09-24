class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 1, low = 0, high =n;
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n);
        dp[0] =  1;
        for(int i=1;i<n;++i)
        {
            for(int j = i-1;j>=0;--j)
            {
                if(intervals[j][1]<= intervals[i][0])
                {
                    dp[i] = dp[j]+1;
                    break;
                }
            }
            if(dp[i]==0)
                dp[i]=1;
        }
        for(int i=0;i<n;++i)
            ans = max(ans, dp[i]);
        return n-ans;
    }
};
/*
1 +1
2 -1
2 +1
4 -1
1 +1
4 -1
1 +1
9 -1

+1 +1 +1 -2 +2 -4 -4 -9

count =2
*/