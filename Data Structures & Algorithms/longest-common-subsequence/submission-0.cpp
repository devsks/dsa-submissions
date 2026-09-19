class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> grid(n+1, vector<int>(m+1));

        for(int i=0;i<=n;++i)
            grid[i][0] = 0;
        for(int j=0;j<=m;++j)
            grid[0][j] = 0;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                if(text1[i-1]==text2[j-1])
                    grid[i][j] = grid[i-1][j-1]+1;
                else
                    grid[i][j] = max({grid[i-1][j-1], grid[i-1][j], grid[i][j-1]});
            }
        }

        return grid[n][m];
    }
};
