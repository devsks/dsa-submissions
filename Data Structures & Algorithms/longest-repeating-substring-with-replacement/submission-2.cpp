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
        int res = low;
        while(low <= high)
        {
            int mid = (low+high)>>1;

            if(isPossible(s,k,mid))
            {
                res = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return res;
    }
};
