struct TrieNode {
   public:
    vector<TrieNode*> entry;
    bool isEnd;
    TrieNode() {
        entry.resize(26, nullptr);
        isEnd = false;
    }
};
class PrefixTree {
   public:
    TrieNode* root;
    PrefixTree() { root = new TrieNode(); }
    void insert(string word) {
        TrieNode* ptr = root;
        for (int i = 0; i < word.length(); ++i) {
            int key = word[i] - 'a';
            if (ptr->entry[key] == nullptr) ptr->entry[key] = new TrieNode();
            ptr = ptr->entry[key];
        }
        ptr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* ptr = root;
        for (int i = 0; i < word.length(); ++i) {
            int key = word[i] - 'a';
            if (ptr->entry[key] == nullptr) return false;
            ptr = ptr->entry[key];
        }
        return ptr->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for (int i = 0; i < prefix.length(); ++i) {
            int key = prefix[i] - 'a';
            if (ptr->entry[key] == nullptr) return false;
            ptr = ptr->entry[key];
        }
        return true;
    }
};
