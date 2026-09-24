class Solution {
   public:
    int solve(string s, int index, unordered_map<int,int> &cache) {
        if (index >= s.length())
            return 1;
        else {
            if(cache.count(index))
                return cache[index];
            int num = 0;
            int count = -1;
            for (int i = index; i < s.length(); ++i) {
                num = num * 10 + (s[i] - '0');
               // cout<<num<<" ";
                if (num == 0 || num > 26) break;
                int nxtCount = solve(s, i + 1, cache);
                if (nxtCount != -1) {
                    if (count == -1)
                        count = nxtCount;
                    else
                        count += nxtCount;
                }
            }
        
            return cache[index] = count;
        }
    }
    int numDecodings(string s) { 
        unordered_map<int,int> cache;
        return max(0,solve(s, 0,cache)); 
    }
};
/*
   1234

1 (234) 12 (34)
  2 (34)
     3 4

*/
