#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Entry {
    int x, y;
    int val;
};

struct Comparator {
    bool operator()(const Entry& e1, const Entry& e2)
    {
        return e1.val > e2.val;
    }
};
// priority_queue<Entry, vector<Entry>, Comparator> Q;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> rightSideView_Iter(TreeNode* root) {
        int h = 0;
        vector<TreeNode*> stack;
        TreeNode* n = root, *prev = root;
        vector<int> ans;
        
        while (n != NULL || !stack.empty()) {
            if (n != NULL) {
                prev = n;
                stack.push_back(n);
                
                if (ans.size() > h) {
                    ans[h] = n->val;
                } else {
                    ans.push_back(n->val);
                }
                
                if (n->left != NULL) {
                    n = n->left;
                } else {
                    n = n->right;
                }
                if (n != NULL) ++h;
            } else {
                n = stack.back();
                TreeNode* curr = n;
                
                if (prev == n->left) {
                    n = n->right;
                    if (n != NULL) ++h;
                } else {
                    --h;
                    stack.pop_back();
                    n = NULL;
                }
                prev = curr;
            }
            
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        mAns.clear();
        
        preOrderTraverse(root, 0);
        return mAns;
    }
    
private:
    void preOrderTraverse(TreeNode* node, int h)
    {
        if (node == NULL) return;
        if (mAns.size() > h) mAns[h] = node->val;
        else mAns.push_back(node->val);
        
        preOrderTraverse(node->left, h + 1);
        preOrderTraverse(node->right, h + 1);
    }
    
    vector<int> mAns;
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
}

void Test0()
{
    Solution sln;
//      1            <---
//    /   \
//    2     3         <---
//    \     \
//    5     4       <---
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.left = &n2; n1.right = &n3;
    n2.right = &n5; n3.right = &n4;
    printVector(sln.rightSideView(&n1));
}

void Test1()
{
    Solution sln;
    //      1            <---
    //    /
    //    2              <---
    //    \
    //    5             <---
    TreeNode n1(1), n2(2), n5(5);
    n1.left = &n2;
    n2.right = &n5;
    printVector(sln.rightSideView(&n1));
}

void Test2()
{
    Solution sln;
    //      1            <---
    //    /
    //    2              <---
    TreeNode n1(1), n2(2);
    n1.left = &n2;
    printVector(sln.rightSideView(&n1));
}


int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
