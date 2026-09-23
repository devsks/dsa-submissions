class Solution {
   public:
    int getExtendedPali(int low, int high, string& s) {
        int count = 0, n = s.length();
        while (low >= 0 && high < n && s[low] == s[high]) {
            count += 1;
            --low;
            ++high;
        }

        return count;
    }
    int countSubstrings(string s) {
        int ans = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            int oddCount = getExtendedPali(i, i, s);
            int evenCount = getExtendedPali(i, i + 1, s);
            ans += oddCount + evenCount;
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
