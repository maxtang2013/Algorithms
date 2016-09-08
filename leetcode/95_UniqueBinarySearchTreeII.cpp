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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
    
private:
    
    vector<TreeNode*> generateTrees(int from, int to) {
        vector<TreeNode*> ans;
        
        if (to == from) {
            ans.push_back(new TreeNode(to));
            return ans;
        }
        
//        TreeNode* root = new TreeNode(from);
//        TreeNode* prev = root;
//        for (int i = from + 1; i <= to; ++i) {
//            TreeNode* node = new TreeNode(i);
//            prev->right = node;
//            prev = node;
//        }
//        ans.push_back(root);
//        
//        root = new TreeNode(to);
//        prev = root;
//        for (int i = to - 1; i >= to; --i) {
//            TreeNode* node = new TreeNode(i);
//            prev->left = node;
//            prev = node;
//        }
//        ans.push_back(root);
        
        for (int i = from; i <= to; ++i) {
            
            vector<TreeNode*> left, right;
            if (i > from) {
                left = generateTrees(from, i - 1);
            }
            if (left.empty()) left.push_back(NULL);
            if (i < to) {
                right = generateTrees(i+1, to);
            }
            if (right.empty()) right.push_back(NULL);
            
            for (TreeNode *l: left) {
                for (TreeNode *r: right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
         }
        
        return ans;
    }
};

void Test0()
{
    Solution sln;
}

int main()
{
    Test0();
    
    return 0;
}
