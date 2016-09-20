#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

struct Node {
    bool isLeaf;
    Node* children[26]{0};
    Node() : isLeaf(false) {}
};

class WordDictionary {
public:
    
    WordDictionary(){
        mRoot = new Node();
    }
    
    ~WordDictionary() {
        destroyAllNodes(mRoot);
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        addWordToNode(word, 0, mRoot);
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, 0, mRoot);
    }
private:
    
    void addWordToNode(const string& word, int i, Node* node) {
        if (i == word.length()) {
            node->isLeaf = true;
            return;
        }
        int idx = word[i] - 'a';
        Node* child = NULL;
        if (node->children[idx] == NULL) {
            child = node->children[idx] = new Node();
        } else {
            child = node->children[idx];
        }
        addWordToNode(word, i+1, child);
    }
    
    bool search(const string& word, int i, Node* root) {
        if (i == word.size()) {
            return root->isLeaf;
        }
        
        if (word[i] == '.') {
            for (int t = 0; t < 26; ++t) {
                if (root->children[t] != NULL && search(word, i + 1, root->children[t]))
                    return true;
            }
        } else {
            int idx = word[i] - 'a';
            if (root->children[idx] != NULL && search(word, i + 1, root->children[idx]))
                return true;
        }
        return false;
    }
    
    void destroyAllNodes(Node* node) {
        for (int it = 0; it != 26; ++it) {
            if (node->children[it] != NULL)
                destroyAllNodes(node->children[it]);
        }
        delete node;
    }
private:
    Node* mRoot;
};
void Test0()
{
    WordDictionary dict;
    //    addWord("bad")
    //    addWord("dad")
//    addWord("mad")
//    search("pad") -> false
//    search("bad") -> true
//    search(".ad") -> true
//    search("b..") -> true
    dict.addWord("bad");
    dict.addWord("dad");
    dict.addWord("mad");
    cout << dict.search("pad") << endl;
    cout << dict.search("bad") << endl;
    cout << dict.search(".ad") << endl;
    cout << dict.search("b..") << endl;
}

int main()
{
    Test0();
    
    return 0;
}
