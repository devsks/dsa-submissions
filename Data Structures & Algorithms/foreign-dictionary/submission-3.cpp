class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> indegree(26,-1);
        string res = "";
        unordered_map<int, set<int>> edges;
        for(char ch : words[0])
            indegree[ch-'a']=0;
        for(int i=1;i<words.size();++i)
        {
            int j =0;
            for(char ch : words[i])
            {
                if(indegree[ch-'a']==-1)
                  indegree[ch-'a']=0;
            }
            while(j< words[i].length() && j < words[i-1].length())
            {
                if(words[i][j]!=words[i-1][j])
                { 

                    if(indegree[words[i-1][j]-'a']==-1)
                        indegree[words[i-1][j]-'a']=0;
                    if(indegree[words[i][j]-'a']==-1)
                        indegree[words[i][j]-'a']=0;
                    if(edges[words[i-1][j]-'a'].count(words[i][j]-'a')==0)
                        indegree[words[i][j]-'a']+=1;
                    edges[words[i-1][j]-'a'].insert(words[i][j]-'a');
                    break;
                }
                ++j;
            }
            if(j == words[i].length() && j<words[i-1].length())
                return res;
        }
        int totalChars=0;
        for(int i=0;i<26;++i)
        {
            if(indegree[i]!=-1)
                ++totalChars;
        }
        queue<int> s;
        for(int i=0;i<26;++i)
        {
            if(indegree[i]==0)
            {
                //cout<<(char)('a'+i)<<" ";
                s.push(i);
            }
        }
        while(!s.empty())
        {
            int top = s.front();
            s.pop();
            res+=(top+'a');
            for(int num : edges[top])
            {
                indegree[num]-=1;
                if(indegree[num]==0)
                    s.push(num);
            }
        }
        if(res.length() != totalChars)
            return "";
        return res;
        
    }
};
