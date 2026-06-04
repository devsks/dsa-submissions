class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sMap(26),tMap(26);
        
        for(char &ch : s)
        {
            ++sMap[ch-'a'];
        }  

        for(char &ch : t)
        {
            ++tMap[ch-'a'];
        }
    
        for(int i=0;i<26;++i)
        {
            if(tMap[i]!=sMap[i])
                return false;
        }
        return true;

    }
};
