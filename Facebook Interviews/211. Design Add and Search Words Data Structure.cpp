class WordDictionary {
private:
    struct TrieNode {
        bool isEndOfWord;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isEndOfWord(false) {}
    };
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(auto c : word) {
            if(p->children.count(c) == 0)
                p->children[c] = new TrieNode();
            p = p->children[c];
        }
        p->isEndOfWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dfs(root, word, 0);
    }
    
    bool dfs(TrieNode* node, string& word, int i) {
        if(i == word.length())
            return node->isEndOfWord;
        if(word[i] == '.') {
            for(auto n : node->children) {
                if(dfs(n.second, word, i+1)) return true;
            }
        }
        if(node->children.count(word[i]) != 0) {
            return dfs(node->children[word[i]], word, i+1);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
