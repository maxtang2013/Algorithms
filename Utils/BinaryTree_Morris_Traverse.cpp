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
    void recoverTree(TreeNode* root) {
        
        recoverTree_Morris(root);
        return;
        
        vector<TreeNode*> S;
        TreeNode* curr, *prev = NULL, *first = NULL, *second = NULL;
        
        curr = root;
        while (curr != NULL || !S.empty()) {
            
            if (curr != NULL) {
                
                S.push_back(curr);
                curr = curr->left;
                
            } else {
                
                curr = S.back();
                S.pop_back();
                
                if (prev != NULL && prev->val >= curr->val) {
                    if (first == NULL) first = prev;
                    
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            }
            
        }
        
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    
    void recoverTree_Morris(TreeNode* root) {
        TreeNode* curr, *prev = NULL, *first = NULL, *second = NULL;
        
        curr = root;
        
        while (curr != NULL) {
            
            if (prev != NULL && prev->val >= curr->val) {
                if (first == NULL) first = prev;
                
                second = curr;
            }
            
            if (curr->left == NULL) {
                
                prev = curr;
                curr = curr->right;
            
            } else {
                
                // Find the right most node.
                TreeNode* rightmost = curr->left;
                while (rightmost->right != NULL && rightmost->right != curr) {
                    rightmost = rightmost->right;
                }
                
                if (rightmost->right == curr) {
                    // we have visited the left sub-tree, delete the link.
                    rightmost->right = NULL;
                    prev = curr;
                    curr = curr->right;
                } else {
                    rightmost->right = curr;
                    // Don't assign curr -> prev here.
                    // Because in an inorder-traverse, curr->left's previous node is curr's parent.
                    curr = curr->left;
                }
            }
        }
        
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
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

int getLastBit(int n)
{
    //    Equavilent:
    //    int mask = 0;
    //    for (i = 0; i < 32; ++i)
    //    {
    //        mask = 1 << i;
    //        if (bits & mask)
    //        {
    //            break;
    //        }
    //    }
    //    return mask;
    
    return n & (-n);
}

void printBits(int n)
{
//    for (int i = 31; i >= 0; --i)
//    {
//        if (n & (1<<i)) std::cout << "1";
//        else std::cout << "0";
//    }
//    std::cout << "\n";
    
    std::bitset<32> bits(n);
    std::cout << bits << "\n";
}

int countBits(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n = n & (n - 1);
    }
    return cnt;
}

void Test0()
{
    Solution sln;
    TreeNode n1(1), n2(2);
    n1.left = &n2;
    sln.recoverTree(&n1);
    
    printf("%d %d\n", n1.val, n2.val);
}

void Test1()
{
    Solution sln;
    TreeNode n1(1), n2(2);
    n2.right = &n1;
    sln.recoverTree(&n2);
    
    printf("%d %d\n", n1.val, n2.val);
}
void Test2()
{
    Solution sln;
    // [2,null,3,1]
    TreeNode n1(2), n2(3), n3(1);
    n1.right = &n2;
    n2.left = &n3;
    sln.recoverTree(&n1);
    
    printf("%d %d %d\n", n1.val, n2.val, n3.val);
}

int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
