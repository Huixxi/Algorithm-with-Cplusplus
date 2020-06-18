## Tire(字典树、前缀树)
面试时候被问到了，让我计算一堆单词中，含有某个特定前缀(prefix)的单词数量有多少，下面给出一种字典树的实现：   

教程：
* [Trie | (Insert and Search)](https://www.geeksforgeeks.org/trie-insert-and-search/)
* [Count the number of words with given prefix using Trie](https://www.geeksforgeeks.org/count-the-number-of-words-with-given-prefix-using-trie/)

算法题：
* [LeetCode 208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

该数据结构和具体实现都比较简单，直接看代码和注释应该就可以理解：
```c++
struct TrieNode {
    map<char, TrieNode*> children;  // 用于存放该节点的所有子节点，也可以用size为26的数组
    bool isEndOfWord;  // 用于判断该节点(字母)是否为一个单词的最后一个字母
    int num;  // 记录该节点(字母)被访问了多少次，用于计算这堆单词中包含某前缀的单词数量
    TrieNode(bool b = false, int n = 0) : isEndOfWord(b), num(n) {}  // 构造函数
};

class Trie {
private:
    TrieNode *root;  // 该树的根节点
    
private:
    // 递归释放树中所有节点所占用的内存资源
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
    Trie() {  // 构造函数
        root = new TrieNode();
    }
    
    ~Trie() {  // 析构函数
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
        p->isEndOfWord = true;  // 在单词的末尾打上标签
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *p = root;
        for(auto& c : word) {
            if(p == nullptr || p->children.count(c) == 0)
                return false;
            p = p->children[c];
        }
        return p->isEndOfWord;  // 别忘了判断word是真正存在于这个树中还是仅仅是个前缀
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
        return true;  // 类似search函数，但是这里不需要判断是否为一个单词
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
