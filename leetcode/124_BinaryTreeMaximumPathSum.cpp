#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int sum = maxPathSumWithoutParent(root);
        if (sum > 0) {
            return sum;
        }
        
        int m = INT_MIN;
        vector<TreeNode*> S;
        S.push_back(root);
        while (!S.empty()) {
            TreeNode* n = S.back();
            S.pop_back();
            
            m = max(m, n->val);
            
            if (n->left) S.push_back(n->left);
            if (n->right) S.push_back(n->right);
        }
        
        return m;
    }
    
private:
    int maxPathSumWithParent(TreeNode* root) {
        if (root == NULL) return 0;
        
        if (mPathSumWithParent.count(root)) {
            return mPathSumWithParent[root];
        }
        
        int sum = max(maxPathSumWithParent(root->left), maxPathSumWithParent(root->right)) + root->val;
        sum = max(sum, 0);
        mPathSumWithParent[root] = sum;
        return sum;
    }
    
    int maxPathSumWithoutParent(TreeNode* root) {
        if (root == NULL) return 0;
        if (mPathSumWithoutParent.count(root)){
            return mPathSumWithoutParent[root];
        }
        
        int sum = max(maxPathSumWithoutParent(root->left), maxPathSumWithoutParent(root->right));
        
        sum = max(sum, root->val + maxPathSumWithParent(root->left) + maxPathSumWithParent(root->right));
        
        sum = max(0, sum);
        
        mPathSumWithoutParent[root] = sum;
        return sum;
    }
    
    unordered_map<TreeNode*, int> mPathSumWithoutParent;
    unordered_map<TreeNode*, int> mPathSumWithParent;
};


void TreeNodeTest()
{
}

void Test0()
{
    Solution sln;
    
    //        1
    //    2      3
    //  4   5  6   7
    //8
    
    TreeNode nodes[] = {1, 2, 3, 4, 5, 6,7 ,8};
    int len = sizeof(nodes) / sizeof(TreeNode);
    for (int i = 0; i < len; ++i) {
        if (i * 2 + 1 < len)
            nodes[i].left = nodes + (i*2+1);
        if (i*2+2<len)
            nodes[i].right = nodes + (i*2+2);
    }

    cout << sln.maxPathSum(nodes) << endl;
}

void Test1()
{
    Solution sln;
       TreeNode nodes[] = {-3};
    int len = sizeof(nodes) / sizeof(TreeNode);
    for (int i = 0; i < len; ++i) {
        if (i * 2 + 1 < len)
            nodes[i].left = nodes + (i*2+1);
        if (i*2+2<len)
            nodes[i].right = nodes + (i*2+2);
    }
    
    cout << sln.maxPathSum(nodes) << endl;
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
