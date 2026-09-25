class Solution {
   public:
    int expand(string& s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            --i;
            ++j;
            count += 2;
        }

        return count;
    }
    string longestPalindrome(string s) {
        int maxLen = 0, start = 0;
        for (int i = 0; i < s.length(); ++i) {
            int len1 = expand(s, i, i) - 1;
            int len2 = expand(s, i, i + 1);

            if (len1 > maxLen) {
                maxLen = len1;
                int half = len1 >> 1;
                start = i - half;
            }
            if (len2 > maxLen) {
                maxLen = len2;
                int half = (len2 >> 1) - 1;
                start = i - half;
            }
        }
        return s.substr(start, maxLen);
    }
};
