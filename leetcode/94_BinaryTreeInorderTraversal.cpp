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
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> stack;
        TreeNode* node = NULL;
        TreeNode* prev = root;
        
        if (root == NULL) return ans;
        
        stack.push_back(root);
        
        while (!stack.empty())
        {
            node = stack.back();
            
            if (prev == node->left)
            {
                ans.push_back(node->val);
                
                if (node->right != NULL)
                    stack.push_back(node->right);
                else
                    stack.pop_back();
            }
            else if (prev == node->right)
            {
                stack.pop_back();
            }
            else
            {
                if (node->left != NULL)
                {
                    stack.push_back(node->left);
                }
                else
                {
                    ans.push_back(node->val);
                    if (node->right != NULL)
                    {
                        stack.push_back(node->right);
                    }
                    else
                    {
                        stack.pop_back();
                    }
                }
            }
            prev = node;
        }
        
        return ans;
    }
    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        TreeNode *n = root;
        vector<int> ans;
        
        while (n != NULL || !stack.empty())
        {
            if (n != NULL)
            {
                stack.push_back(n);
                n = n->left;
            }
            else
            {
                n = stack.back();
                stack.pop_back();
                ans.push_back(n->val);
                
                n = n->right;
            }
        }
        return ans;
    }
    
    // 144.   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        TreeNode *n = NULL;
        vector<int> ans;
        
        if (root == NULL) return ans;
        
        stack.push_back(root);
        while (!stack.empty())
        {
            n = stack.back();
            stack.pop_back();
            ans.push_back(n->val);
            
            if (n->right != NULL)
                stack.push_back(n->right);
            
            if (n->left != NULL)
                stack.push_back(n->left);
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

void Test0()
{
    Solution sln;
    
    //      1
    //       \
    //        2
    //       /
    //      3
    TreeNode n1(1), n2(2), n3(3);
    n1.right = &n2;
    n2.left = &n3;
    
    printVector(sln.inorderTraversal(&n1));
}

void Test1()
{
    Solution sln;
    
    TreeNode n1(3), n2(1), n3(2);
    n1.left = &n2;
    n1.right = &n3;
    
    printVector(sln.inorderTraversal(&n1));
}

void Test2()
{
    Solution sln;
    
    //                  1
    //              2      3
    //           4    5  6    7
    //        8
    //
    //
    
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8);
    n1.left = &n2; n1.right = &n3;
    n2.left = &n4; n2.right = &n5;
    n3.left = &n6; n3.right = &n7;
    n4.left = &n8;
                                                   
    
    printVector(sln.inorderTraversal(&n1));
}

int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
