class Solution {
public:
    int numDecodings(string s) {
        int ans =0; 
        if(s[0] == '0')
            return ans;
        vector<int> dp(2,1);
        for(int i=1;i<s.length();++i)
        {
            int count = 0;
            int digit = s[i]-'0';
            int twoDigits = (s[i-1]-'0')*10 + (s[i]-'0');
            if(digit > 0)
                count += dp[1];
            if(twoDigits > 9 && twoDigits < 27)
                count+=dp[0];
            dp[0] = dp[1];
            dp[1] = count;

        }
        return dp[1];
    }
};
