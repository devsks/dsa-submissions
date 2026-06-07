class Solution {
public:
    const string delim = "<-&->";
    string encode(vector<string>& strs) {
        string encoded;
        
                encoded.append(delim);
        for(int i=0;i<strs.size();++i)
        {
            encoded.append(strs[i]);
            encoded.append(delim);
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int start =delim.length(), found =s.find(delim,start);
        while(found != string::npos)
        {
            strs.push_back(s.substr(start,found-start));
            start = found+delim.length();
            found = s.find(delim,start);
        }

        return strs;

    }
};
