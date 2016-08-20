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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> ans;
        
        TreeNode* n = root, *prev = n;
        while (n != NULL || !stack.empty())
        {
            if (n != NULL)
            {
                stack.push_back(n);
                prev = n;
                
                if (n->left == NULL)
                {
                    n = n->right;
                }
                else
                {
                    n = n->left;
                }
            }
            else
            {
                n = stack.back();
                TreeNode* curr = n;
                
                if (prev == n->left)
                {
                    n = n->right;
                }
                else
                {
                    stack.pop_back();
                    ans.push_back(n->val);
                    n = NULL;
                }
                prev = curr;
            }
        }
        return ans;
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
    //    1
    //   / \
    //   3  2
    Solution sln;
    TreeNode n1(1), n2(2), n3(3);
    n1.right = &n2;
    n2.left = &n3;
    printVector(sln.postorderTraversal(&n1));
    
}

void Test1()
{
    //             1
    //              \
    //               2
    //              / \
    //              3  4
    Solution sln;
    TreeNode n1(1), n2(2), n3(3), n4(4);
    n1.right = &n2;
    n2.left = &n3;
    n2.right = &n4;
    printVector(sln.postorderTraversal(&n1));
    
}

void Test2()
{
    Solution sln;
    TreeNode n1(1), n2(2), n3(3), n4(4);
    n1.right = &n2;
    n2.left = &n3;
    n1.left = &n4;
    printVector(sln.postorderTraversal(&n1));
    
}

int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
