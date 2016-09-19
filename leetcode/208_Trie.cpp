#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : isWord(false) {
        
    }
    
    TrieNode* children[26]{0};
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        destroyAllNodes(root);
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        insert(word, 0, root);
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        return search(word, 0, root);
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return searchPrefix(prefix, 0, root);
    }
    
private:
    void insert(const string& word, int i, TrieNode* node) {
        if (i == word.size()) {
            node->isWord = true;
            return;
        }
        int idx = word[i] - 'a';
        TrieNode* child = NULL;
        if (node->children[idx] == NULL) {
            child = node->children[idx] = new TrieNode();
        } else {
            child = node->children[idx];
        }
        insert(word, i + 1, child);
    }
    bool search(const string& word, int i, TrieNode* node) {
        if (i == word.size()) {
            return node->isWord;
        }
        
        int idx = word[i]-'a';
        if (node->children[idx] != NULL && search(word, i + 1, node->children[idx]))
            return true;
        return false;
    }
    
    bool searchPrefix(const string& word, int i, TrieNode* node) {
        if (i == word.size()) {
            return true;
        }
        
        int idx = word[i]-'a';
        if (node->children[idx] != NULL && searchPrefix(word, i + 1, node->children[idx]))
            return true;
        return false;
    }
    
    void destroyAllNodes(TrieNode* node) {
        for (int i = 0; i < 26; ++i) {
            if (node->children[i] != NULL) {
                destroyAllNodes(node->children[i]);
            }
        }
        delete node;
    }
    
private:
    TrieNode* root;
};

void Test0()
{
    Trie dict;
    dict.insert("bad");
    dict.insert("dad");
    dict.insert("mad");
    cout << dict.search("pad") << endl;
    cout << dict.search("bad") << endl;
}

void Test1()
{
    Trie dict;
    dict.insert("ab");
    cout << dict.search("a") << endl;
    cout << dict.startsWith("a") << endl;
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
