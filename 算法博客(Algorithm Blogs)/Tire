## 字典树
面试时候被问到了，让我计算一堆单词中，含有某个特定前缀(prefix)的单词数量有多少，下面给出一种字典树的实现：   
参考：
* [Trie | (Insert and Search)](https://www.geeksforgeeks.org/trie-insert-and-search/)
* [Count the number of words with given prefix using Trie](https://www.geeksforgeeks.org/count-the-number-of-words-with-given-prefix-using-trie/)
* [LeetCode 208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

```c++
struct TrieNode {
    map<char, TrieNode*> children;
    bool isEndOfWord;
    int num;
    TrieNode(bool b = false, int n = 0) : isEndOfWord(b), num(n) {}
};

class Trie {
private:
    TrieNode *root;
    
private:
    void clear(TrieNode *root){
        for(auto& child : root->children){
            if(child.second != nullptr){
                clear(child.second);
            }
        }
        delete root;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        clear(root);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *p = root;
        for(auto& c : word) {
            if(p->children.count(c) == 0)
                p->children[c] = new TrieNode();
            p = p->children[c];
            ++(p->num);
        }
        p->isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(auto& c : word) {
            if(p == nullptr || p->children.count(c) == 0)
                return false;
            p = p->children[c];
        }
        return p->isEndOfWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(auto& c : prefix) {
            if(p == nullptr || p->children.count(c) == 0)
                return false;
            p = p->children[c];
        }
        // cout << p->num << endl;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```
