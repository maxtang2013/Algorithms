#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *levelHead = root;
        
        while (levelHead != NULL) {
            TreeLinkNode* nextLevelHead = NULL;
            TreeLinkNode* prev = NULL;
            for (TreeLinkNode* n = levelHead; n != NULL; n = n->next) {
                if (nextLevelHead == NULL && n->left != NULL) {
                        nextLevelHead = n->left;
                }
                if (nextLevelHead == NULL && n->right != NULL) {
                    nextLevelHead = n->right;
                }
                
                if (n->left != NULL) {
                    if (prev != NULL) {
                        prev->next = n->left;
                    }
                    prev = n->left;
                }
                
                if (n->right != NULL) {
                    if (prev != NULL) {
                        prev->next = n->right;
                    }
                    prev = n->right;
                }
            }
            levelHead = nextLevelHead;
        }
    }
};

void TreeNodeTest()
{
    Solution sln;
    
    //        1
    //    2      3
    //  4   5  6   7
    //8
    
    TreeLinkNode nodes[] = {1, 2, 3, 4, 5, 6,7 ,8};
    int len = sizeof(nodes) / sizeof(TreeLinkNode);
    for (int i = 0; i < len; ++i) {
        if (i * 2 + 1 < len)
            nodes[i].left = nodes + (i*2+1);
        if (i*2+2<len)
            nodes[i].right = nodes + (i*2+2);
    }
}

void Test0()
{
    Solution sln;
    
}

int main()
{
    Test0();
    
    return 0;
}
