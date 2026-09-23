class Solution {
   public:
    int countSubstrings(string s) {
        int ans = 0, n = s.length();
        vector<vector<bool>> isPali(n, vector<bool>(n));
        ans = n;
        for (int i = 0; i < n; ++i) isPali[i][i] = true;
        for (int i = 0; i < n; ++i) {
            if (i + 1 < n && s[i] == s[i + 1]) 
            {
                ++ans;
                isPali[i][i + 1] = true;
            }
        }
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n; ++i) {
                int j = i + len - 1;
                if (j >= n) break;
                if (s[i] == s[j]) {
                    if (isPali[i + 1][j - 1]) {
                        isPali[i][j] = true;
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};
/*
abcba
1 0 0 0 1
0 1 0 1 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
*/
