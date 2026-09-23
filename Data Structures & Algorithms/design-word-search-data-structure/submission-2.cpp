class WordDictionary {
   public:
    struct Trie {
       public:
        bool isWord = false;
        vector<Trie*> entry;
        Trie() { entry.resize(26, nullptr); }
    };
    Trie* root;
    WordDictionary() { root = new Trie(); }

    void addWord(string word) {
        Trie* ptr = root;
        for (int i = 0; i < word.length(); ++i) {
            int key = word[i] - 'a';
            if (ptr->entry[key] == nullptr) ptr->entry[key] = new Trie();
            ptr = ptr->entry[key];
        }
        ptr->isWord = true;
    }
    bool searchHelper(string word, int index, Trie* ptr)
    {
        if(index == word.length())
            return ptr == nullptr ? false:  ptr->isWord;
        else
        {
            if(word[index] == '.')
            {
                for(int i=0;i<26;++i)
                {
                    if(ptr->entry[i]!= nullptr)
                    {
                        bool found = searchHelper(word,index+1,ptr->entry[i]);
                        if(found)
                            return true;
                    }
                }
                return false;
            }
            else
            {
                if(ptr->entry[word[index]-'a']==nullptr)
                    return false;
                else
                    return searchHelper(word, index+1,ptr->entry[word[index]-'a']);
            }
        }
    }
    bool search(string word) {
        return searchHelper(word,0,root);
    }
};
