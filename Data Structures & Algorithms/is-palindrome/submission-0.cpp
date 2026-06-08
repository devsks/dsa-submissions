class Solution {
public:
    bool isPalindrome(string s) {
        string aplhanumStr;
        aplhanumStr.reserve(s.length());
        for(char ch :s)
        {
            if(isalnum(ch))
                aplhanumStr+=tolower(ch);
        }
        int len = aplhanumStr.length();
        for(int i=0;i<len/2;++i)
        {
            if(aplhanumStr[i]!= aplhanumStr[len-i-1])
                return false;
        }
        return true;
    }
};
