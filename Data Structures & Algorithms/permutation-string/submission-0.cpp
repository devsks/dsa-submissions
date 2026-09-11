class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()< s1.length())
            return false;
        
        unordered_map<char,int> hashOfS1, hashOfS2;
        for(char c: s1)
        {
            hashOfS1[c]+=1;
        }
        int i =0;
        for( ;i<s1.length();++i)
        {
            hashOfS2[s2[i]]+=1;
        }

        do
        {   
            bool allMatch = true;
            for(int j=0;j<26;++j)
            {
                if(hashOfS1['a'+j]!=hashOfS2['a'+j])
                {
                    allMatch=false;
                    break;
                }
            }

            if(allMatch)
                return true;
            hashOfS2[s2[i-s1.length()]]-=1;
            if(i < s2.length())
                hashOfS2[s2[i]]+=1;
            ++i;
        }while(i <= s2.length());

        return false;
    }
};
