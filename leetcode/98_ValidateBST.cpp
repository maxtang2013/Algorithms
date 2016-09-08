#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> S;
        TreeNode* n = root;
        TreeNode* prev = NULL;
        
        while (n != NULL || !S.empty()) {
            if (n != NULL) {
                S.push_back(n);
                n = n->left;
            } else {
                n = S.back();
                S.pop_back();
                
                // Visit the node here.
                
                if (prev != NULL && prev->val >= n->val) {
                    return false;
                }
                
                // Previous node is the node we've just visited.
                prev = n;
                
                n = n->right;
            }
        }
        
        return true;
    }
};

void Test0()
{
    Solution sln;
    
    TreeNode nodes[] = {{5}, {3}, {8}, {1}, {4}, {6}};
    int len = sizeof(nodes) / sizeof (TreeNode);
    for (int i = 0; i < len; ++i) {
        if (i * 2 + 1 < len)
            nodes[i].left = nodes + (i*2+1);
        if (i * 2 + 2 < len)
            nodes[i].right = nodes + (i*2+2);
    }
    cout << sln.isValidBST(nodes) << endl;
    
}

void Test1()
{
    Solution sln;
    
    //       5
    //     /   \
    //    3     8
    //   / \    /
    //  1  2   6
    TreeNode nodes[] = {{5}, {3}, {8}, {1}, {2}, {6}};
    int len = sizeof(nodes) / sizeof (TreeNode);
    for (int i = 0; i < len; ++i) {
        if (i * 2 + 1 < len)
            nodes[i].left = nodes + (i*2+1);
        if (i * 2 + 2 < len)
            nodes[i].right = nodes + (i*2+2);
    }
    cout << sln.isValidBST(nodes) << endl;
    
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
