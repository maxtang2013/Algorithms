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

struct TreeNodeItem {
    TreeNode* node;
    int sum;
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        vector<TreeNodeItem> S;
        TreeNodeItem i = {root, root->val};
        while (i.node != NULL || !S.empty()) {
            if (i.node != NULL) {
                S.push_back(i);
                
                if (i.node->left != NULL) {
                    i.sum += i.node->left->val;
                }
                i.node = i.node->left;
            } else {
                i = S.back();
                S.pop_back();
                
                if (i.node->left == NULL && i.node->right == NULL) {
                    if (sum == i.sum) return true;
                }
                
                if (i.node->right != NULL) {
                    i.sum += i.node->right->val;
                }
                i.node = i.node->right;
            }
        }
        return false;
    }
};

void Test0()
{
    Solution sln;
    TreeNode nodes[] = {1};
    cout << sln.hasPathSum(nodes, 1) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
