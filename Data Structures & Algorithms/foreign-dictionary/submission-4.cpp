class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        vector<int> indegree(26, -1);
        string res = "";
        unordered_map<int, unordered_set<int>> edges;

        for (int i = 0; i < words.size(); ++i) {
            for (char ch : words[i]) {
                if (indegree[ch - 'a'] == -1) indegree[ch - 'a'] = 0;
            }
        }

        for (int i = 1; i < words.size(); ++i) {
            int j = 0;
            while (j < words[i].length() && j < words[i - 1].length()) {
                int u = words[i - 1][j] - 'a', v = words[i][j] - 'a';
                if (u != v) {
                    if (edges[u].count(v) == 0) {
                        indegree[v] += 1;
                        edges[u].insert(v);
                    }
                    break;
                }
                ++j;
            }
            // ab <> abc
            if (j == words[i].length() && j < words[i - 1].length()) 
            return res;
        }

        int totalChars = 0;
        for (int i = 0; i < 26; ++i) {
            if (indegree[i] != -1) ++totalChars;
        }

        queue<int> s;
        for (int i = 0; i < 26; ++i) {
            if (indegree[i] == 0) {
                // cout<<(char)('a'+i)<<" ";
                s.push(i);
            }
        }
        while (!s.empty()) {
            int u = s.front();
            s.pop();
            res += (u + 'a');
            for (int v : edges[u]) {
                indegree[v] -= 1;
                if (indegree[v] == 0) s.push(v);
            }
        }
        // all chars should be there
        if (res.length() != totalChars) return "";
        return res;
    }
};
