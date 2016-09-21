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
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        
        int height = 0;
        TreeNode* n = root;
        while (n != NULL) {
            ++height;
            n = n->left;
        }
        
        int hi = (1<<(height-1)), low = 0;
        
        while (low < hi) {
            int mid = low + (hi - low) / 2;
            
            n = root;
            for (int h = height - 1; n != NULL && h > 0; --h) {
                if (mid & (1 << (h-1))) {
                    n = n->right;
                } else {
                    n = n->left;
                }
            }
            
            if (n == NULL) {
                hi = mid;
            } else {
                low = mid + 1;
            }
        }
        return (1<<(height-1)) + hi - 1;
    }
};

void Test0()
{
    Solution sln;
    TreeNode ns[] = {{1}, {2}, {3}, {4}};
    int len = sizeof(ns) / sizeof(TreeNode);
    for (int i = 0; i < len; ++i) {
        int j = i * 2 + 1;
        if (j < len) ns[i].left = &ns[j];
        if (j + 1 < len) ns[i].right = &ns[j+1];
    }
    
    cout << sln.countNodes(ns) << endl;
}

void Test1()
{
    Solution sln;
    TreeNode ns[] = {{1}, {2}, {3}, {4}, {5}};
    int len = sizeof(ns) / sizeof(TreeNode);
    for (int i = 0; i < len; ++i) {
        int j = i * 2 + 1;
        if (j < len) ns[i].left = &ns[j];
        if (j + 1 < len) ns[i].right = &ns[j+1];
    }
    
    cout << sln.countNodes(ns) << endl;
}


int main()
{
    Test0();
    Test1();
    
    return 0;
}
