class Solution {
public:
    bool isPossible(string s, int k, int target)
    {
        int maxLen=1;
        vector<int> hmap(26);
        int i=0,j;
        while(i < s.length() && i < target)
        {
            hmap[s[i]-'A']++;
            ++i;
        }
        j=i;
        i=0;
        do
        {
            for(int f=0;f<26;++f)
            {
                if(hmap[f]+k >= target)
                {
                    return true;
                }
            }
            if(j<s.length())
            {
                hmap[s[i++]-'A']--;
                hmap[s[j]-'A']++;
            }
            ++j;
        }while(j<= s.length());

        return false;
    }
    int characterReplacement(string s, int k) {
        int low =1, high = s.length();
        int maxLen = min(1+k,(int)s.length());
        vector<int> fq(26);
        int end = 0,start=0, maxFq=1;

        while(end <= k && end < s.length())
        {
            fq[s[end]-'A']++;
            maxFq =max(maxFq,fq[s[end]-'A']);
            ++end;
        }
        while(end < s.length())
        {
            //cout<<start<<" "<<end;
            fq[s[end]-'A']++;

            maxFq =max(maxFq,fq[s[end]-'A']);
            ++end;
            int cur_len = end-start;
            // check if we can expand
            if(cur_len - maxFq >k)
            {
                fq[s[start]-'A']--;
                ++start;
                --cur_len;
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
