#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

struct MyTreeNode {
    MyTreeNode* left;
    MyTreeNode* right;
    int height;
    int l;
    int r;
    MyTreeNode():left(NULL),right(NULL),height(0),l(0),r(0){}
    MyTreeNode(int l, int r, int h):left(NULL),right(NULL),height(h),l(l),r(r){}
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return vector<pair<int, int> >();
        int n = (int) buildings.size();
        int left = buildings[0][0], right = 0;
        
        for (int i = 0; i < n; ++i)
        {
            right = max(right, buildings[i][1]);
        }
        
        mBuildings = buildings;
        
        MyTreeNode* root = buildTree(left, right);
        
//        printTree(root);
//        printf("\n");
        
        vector<pair<int, int> > ans;
        int prev = 0;
        
        for (int i = 0; i < n; ++i)
        {
            int l = buildings[i][0], r = buildings[i][1];
            int h = buildings[i][2];
            int ht = getHeight(root, l);
            if (ht != prev && ht == buildings[i][2])
            {
                ans.push_back(make_pair(l, ht));
                prev = ht;
            }
            
            ht = getHeight(root, r);
            if (ht < h)
            {
                // may cause duplication, because r[i] == l[j] may be true for some j > i.
                ans.push_back(make_pair(r, ht));
            }
        }
        
        sort(ans.begin(), ans.end());
        vector<pair<int, int>> realans;
        
        realans.push_back(ans[0]);
        for (int i = 1; i < ans.size(); ++i)
        {
            if (ans[i].second == ans[i-1].second)
                continue;
            
            realans.push_back(ans[i]);
        }
        
        realans.push_back(make_pair(right, 0));
        
        deleteTree(root);
        
        return realans;
    }
    
private:
    MyTreeNode* buildTree(int leftmost, int rightmost)
    {
        MyTreeNode* root = new MyTreeNode(leftmost, rightmost, 0);
        
        for (int i = 0; i < mBuildings.size(); ++i)
        {
            insert(root, mBuildings[i][0], mBuildings[i][1], mBuildings[i][2]);
//            printTree(root);
//            printf("\n");
        }
        
        return root;
    }
    
    void printTree(MyTreeNode* node)
    {
        if (node->left == NULL && node->right == NULL)
        {
            printf("(%d, %d, %d) ", node->l, node->r, node->height);
            return;
        }
        
        printTree(node->left);
        printTree(node->right);
    }
    
    void deleteTree(MyTreeNode* node)
    {
        if (node == NULL) return;
        deleteTree(node->left);
        deleteTree(node->right);
        
        delete node;
    }
    
    void insert(MyTreeNode *node, int l, int r, int h)
    {
        if (node->left == NULL && node->right == NULL && node->l == l && node->r == r)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            node->left = node->right = NULL;
            if (node->height < h) node->height = h;
            return;
        }
        
        int mid = (int)((node->l + (long long)node->r) / 2);
        
        if (node->left == NULL && mid > node->l)
        {
            node->left = new MyTreeNode(node->l, mid, node->height);
        }
        
        if (node->right == NULL && mid < node->r)
        {
            node->right = new MyTreeNode(mid, node->r, node->height);
        }
        
        if (l < mid)
            insert(node->left, l, min(mid,r), h);
        if (mid < r)
            insert(node->right, max(l, mid), r, h);
    }
    
    int getHeight(MyTreeNode* node, int x)
    {
        if (node->left == NULL)
        {
            return node->height;
        }
        int mid = (node->l + (long long)node->r)/2;
        if (x < mid)
        {
            return getHeight(node->left, x);
        }
        return getHeight(node->right, x);
    }
    
    
    vector<vector<int>> mBuildings;
};

void printVector(const vector<pair<int, int>>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << "(" << list[i].first << "," << list[i].second << ")";
        
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
}

void Test0()
{
    Solution sln;
    
    vector<vector<int>> blds =
    { {2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8} };
    //[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ]
    printVector(sln.getSkyline(blds));
}
void Test1()
{
    Solution sln;
    vector<vector<int>> blds = {{0,2147483647,2147483647}};
    printVector(sln.getSkyline(blds));
}

void Test2()
{
    
    Solution sln;
    vector<vector<int>> blds = {{1,2,1},{1,2,2},{1,2,3}};
    printVector(sln.getSkyline(blds));
}

void Test3()
{
    Solution sln;
    vector<vector<int>> blds = {{1,2,1},{2147483646,2147483647,2147483647}};
    printVector(sln.getSkyline(blds));
}


int main()
{
//    Test0();
//    Test1();
    // Test2();
    Test3();
    return 0;
}
