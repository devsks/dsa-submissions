class Solution {
   public:
    string minWindow(string s, string t) {
        int ind = -1, minLen = s.length()+1;
        int start = 0, end = 0;
        vector<int> fq_t(128), fq_s(128);

        int unq_t = 0, unq_s = 0;
        for (char c : t) {
            ++fq_t[c];
            if (fq_t[c] == 1) ++unq_t;
        }

        while (end < s.length()) {
            char ch = s[end];
            fq_s[ch]++ ;
            if(fq_t[ch]==fq_s[ch])
            {
                ++unq_s;
            }
            while(start<=end && unq_s==unq_t)
            {
                int cur_len = end-start+1;
                if(cur_len < minLen)
                {
                    ind = start;
                    minLen = cur_len;
                }
                ch = s[start];
                if(fq_t[ch]==fq_s[ch])
                {
                    --unq_s;
                }
                --fq_s[ch];
                ++start;
            }
            ++end;
        }
        return ind == -1 ? "" : s.substr(ind, minLen);
    }
};
