class Solution {
   public:
    struct TrieNode {
       public:
        vector<TrieNode*> entry;
        bool isEnd;
        TrieNode() {
            entry.resize(26, nullptr);
            isEnd = false;
        }
    };

    void addWord(string& s, int i, TrieNode* ptr) {
        if (i == s.length())
            ptr->isEnd = true;
        else {
            int key = s[i] - 'a';

            if (ptr->entry[key] == nullptr) ptr->entry[key] = new TrieNode();

            addWord(s, i + 1, ptr->entry[key]);
        }
    }

    bool dfs(string& s, int start, TrieNode* root, vector<int>& cache) {
        if (start == s.length()) return true;

        if (cache[start] != -1) return (bool)cache[start];
        TrieNode * ptr = root;

        for (int i = start; i < s.length(); ++i) {
            int key = s[i] - 'a';

            if (ptr->entry[key] == nullptr) break;

            ptr = ptr->entry[key];

            if (ptr->isEnd) {
                bool match = dfs(s, i + 1, root, cache);
                if (match) return cache[start] = match;
            }
        }

        return cache[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        vector<int> cache(s.length(), -1);

        for (string& word : wordDict) {
            addWord(word, 0, root);
        }

        bool res = dfs(s, 0, root, cache);
        return res;
    }
};
