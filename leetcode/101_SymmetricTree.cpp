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
    bool isSymmetric(TreeNode* root) {
        TreeNode* n = root;
        vector<TreeNode*> S;
        vector<TreeNode*> leftTraverse;
        vector<TreeNode*> rightTraverse;
        S.push_back(root);
        
        while (!S.empty()) {
            n = S.back();
            S.pop_back();
            
            leftTraverse.push_back(n);
            if (n == NULL) continue;
            
            S.push_back(n->left);
            S.push_back(n->right);
        }
        
        S.push_back(root);
        while (!S.empty()) {
            n = S.back();
            S.pop_back();
            
            rightTraverse.push_back(n);
            if (n == NULL) continue;
            S.push_back(n->right);
            S.push_back(n->left);
        }
        
        for (int i = 0; i < leftTraverse.size(); ++i) {
            if ((leftTraverse[i] == NULL && rightTraverse[i] == NULL)
                || (rightTraverse[i] != NULL && leftTraverse[i] != NULL && leftTraverse[i]->val== rightTraverse[i]->val))
                continue;
            return false;
        }
        return true;
    }
    
    bool isSymmetric_rec(TreeNode* root) {
        traverse(root);
        traverseRight(root);
        
        for (int i = 0; i < mLeftInorder.size(); ++i) {
            if ((mLeftInorder[i] == NULL && mRightInorder[i] == NULL)
                || (mRightInorder[i] != NULL && mLeftInorder[i] != NULL && mLeftInorder[i]->val== mRightInorder[i]->val))
                continue;
            return false;
        }
        return true;
    }
    
private:
    void traverse(TreeNode* node) {
        mLeftInorder.push_back(node);
        if (node == NULL) return;
        traverse(node->left);
        traverse(node->right);
    }
    void traverseRight(TreeNode* node) {
        mRightInorder.push_back(node);
        if (node == NULL) return;
        traverseRight(node->right);
        traverseRight(node->left);
    }
    
    vector<TreeNode*> mLeftInorder;
    vector<TreeNode*> mRightInorder;
};

template<typename T>
void printVector(const vector<T>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
    cout << endl;
}

void Test0()
{
    Solution sln;
    TreeNode nodes[] = {{1},{2},{2},{3},{4},{4},{3}};
    int len = sizeof(nodes) / sizeof(TreeNode);
    for (int i = 0; i < len; i++) {
        if (i * 2 + 1 < len) {
            nodes[i].left = nodes + (i*2+1);
        }
        if (i * 2 + 2 < len) {
            nodes[i].right = nodes + (i*2+2);
        }
    }
    
    cout << sln.isSymmetric(nodes) << endl;
}

void Test1()
{
    //        1
    //       / \
    //      2   3
    //      /   /
    //     3   2
    Solution sln;
    TreeNode nodes[] = {{1},{2},{3},{3},{0},{2},{0}};
    int len = sizeof(nodes) / sizeof(TreeNode);
    for (int i = 0; i < len; i++) {
        if (i * 2 + 1 < len) {
            nodes[i].left = nodes + (i*2+1);
        }
        if (i * 2 + 2 < len) {
            nodes[i].right = nodes + (i*2+2);
        }
    }
    nodes[1].right = NULL;
    nodes[2].right = NULL;
    
    cout << sln.isSymmetric(nodes) << endl;
    
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
