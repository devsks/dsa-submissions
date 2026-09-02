class Solution {
public:

    int characterReplacement(string s, int k) {
        int low =1, high = s.length();
        int maxLen = min(1+k,(int)s.length());
        vector<int> fq(26);
        int end = 0,start=0, maxFq=1;
        // create the initial max possible window that is 1+k
        while(end <= k && end < s.length())
        {
            fq[s[end]-'A']++;
            maxFq =max(maxFq,fq[s[end]-'A']);
            ++end;
        }
        while(end < s.length())
        {
            fq[s[end]-'A']++;
            // keep track of the maxFq in the window
            maxFq =max(maxFq,fq[s[end]-'A']);
           // expand the window
            ++end;
            int cur_len = end-start;
            // check if we can really expand otherwise trim
            if(cur_len - maxFq >k)
            {
                fq[s[start]-'A']--;
                ++start;
                --cur_len;
                // making it zero to find out better answer
                maxFq=0;
            }
            else
            {
                maxLen = max(maxLen,cur_len);
            }
          //  cout<<"->"<<maxLen<<endl;
        }
        return maxLen;
    }
};
