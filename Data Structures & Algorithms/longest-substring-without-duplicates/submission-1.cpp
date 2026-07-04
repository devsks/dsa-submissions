class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256,-1);

        int low =0,high=0, maxLen =0;

        for(int i=0;i<s.length();++i)
        {
            if(lastSeen[s[i]] >=low)
            {
                low =lastSeen[s[i]]+1;
                
            }
            lastSeen[s[i]] =i;
            maxLen = max(maxLen, i-low+1); 
        }

        return maxLen;

    }
};
