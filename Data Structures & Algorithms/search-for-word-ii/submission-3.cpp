class Solution {
   public:
    struct Trie {
       public:
        bool isWord = false;
        vector<Trie*> entry;
        Trie() { entry.resize(27); }
    };

    void addWord(Trie* ptr, string &word) {
        for (int i = 0; i < word.length(); ++i) {
            int key = word[i] - 'a';
            
            if (ptr->entry[key] == nullptr)
                ptr->entry[key] = new Trie();
            ptr = ptr->entry[key];
        }
        ptr->isWord = true;
    }
    bool remove_word(Trie* ptr, string word, int i) {
        if (i == word.length()) {
            ptr->isWord = false;
            for (int i = 0; i < 26; ++i)
                if (ptr->entry[i]) return false;
            return true;
        } else {
            bool isSafe = remove_word(ptr->entry[word[i] - 'a'], word, i + 1);
            if (isSafe == true) {
                ptr->entry[word[i] - 'a'] = nullptr;
                for (int i = 0; i < 26; ++i)
                    if (ptr->entry[i]) return false;
                return true;
            }
            return false;
        }
    }
    void DFS(string& cur_word, Trie* ptr, vector<vector<char>>& board,
             vector<vector<bool>>& visited, int i, int j, vector<string>& ans, Trie* root) {
        int n = board.size(), m = board[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || ptr == nullptr) return;

        visited[i][j] = true;
        ptr = ptr->entry[board[i][j] - 'a'];

        if (ptr) {
            cur_word += board[i][j];

            vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
            if (ptr->isWord) {
                remove_word(root, cur_word, 0);
                ans.push_back(cur_word);
            }

            for (auto &dir : dirs) {
                int ni = i + dir[0], nj = j + dir[1];
                DFS(cur_word, ptr, board, visited, ni, nj, ans, root);
            }
            cur_word.pop_back();
        }
        visited[i][j] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        Trie* root = new Trie();

        for (string &word : words) {
           addWord(root, word);
        }
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        string word = "";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                DFS(word, root, board, visited, i, j, ans, root);
            }
        }
        return ans;
    }
};
