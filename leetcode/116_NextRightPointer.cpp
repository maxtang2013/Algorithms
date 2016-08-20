#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        while (root != NULL)
        {
            TreeLinkNode* parent = root, *nextParent = root->next;
            
            while (parent != NULL)
            {
                nextParent = parent->next;
                
                if (parent->left != NULL)
                    parent->left->next = parent->right;
                
                if (parent->right != NULL && nextParent != NULL)
                    parent->right->next = nextParent->left;
                
                parent = parent->next;
            }
            root = root->left;
        }
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
}

int main()
{
    Test0();
    
    return 0;
}
