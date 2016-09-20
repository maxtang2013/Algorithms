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

struct TreeNodeItem {
    TreeNode* node;
    int height;
    int lheight;
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        mBanlenced = true;
        
        postorderTraverse(root);
        //getHeight(root);
        return mBanlenced;
    }
    
    void postorderTraverse(TreeNode* root) {
        vector<TreeNodeItem> S;
        TreeNodeItem i = {root, 1, 0};
        
        TreeNodeItem prev = {NULL, 0, 0};
        
        while (i.node != NULL || !S.empty()) {
            if (i.node != NULL) {
                S.push_back(i);
                
                i.height++;
                i.node = i.node->left;
            } else {
                i = S.back();
                
                if (i.node->left != NULL && prev.node == i.node->left) {
                    S[S.size()-1].lheight = prev.height;
                }
                
                if (i.node->right == NULL || prev.node == i.node->right) {
                    
                    int lheight = i.node->left == NULL ? i.height : i.lheight;
                    if (i.node->right != NULL && abs(lheight - prev.height) > 1) {
                        mBanlenced = false;
                        break;
                    }
                    
                    S.pop_back();
                    i.height = max(prev.height, lheight) + 1;
                    prev = i;
                    i.node = NULL;
                } else {
                    ++i.height;
                    i.node = i.node->right;
                }
            }
        }
    }
    
private:
    
    
    int getHeight(TreeNode* root) {
        if (root == NULL) return 0;
        int hl = getHeight(root->left);
        int hr = getHeight(root->right);
        if (abs(hl - hr) > 1) {
            mBanlenced = false;
        }
        return max(hl, hr);
    }
    bool mBanlenced;
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
template <typename T>
void printBoard(const vector<vector<T>>& board) {
    int n = (int)board.size();
    for (int i = 0; i < n; ++i) {
        int m = (int)board[i].size();
        for (int j = 0; j < m; ++j) {
            cout << board[i][j];
            if (j < m - 1) cout << " ";
            else cout << endl;
        }
    }
    cout << endl;
}

void printfLinkedList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
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

//vector<vector<int>> levelOrder(TreeNode* root) {
//    vector<vector<int>> ans;
//    if (root == NULL) return ans;
//    
//    vector<TreeNodeItem> S;
//    TreeNodeItem item = {root, 0};
//    S.push_back(item);
//    while (!S.empty()) {
//        item = S.back();
//        S.pop_back();
//        
//        if (item.level >= ans.size()) {
//            ans.push_back(vector<int>());
//        }
//        ans[item.level].push_back(item.node->val);
//        
//        if (item.node->right != NULL) {
//            TreeNodeItem item1 = {item.node->right, item.level + 1};
//            S.push_back(item1);
//        }
//        if (item.node->left != NULL) {
//            TreeNodeItem item1 = {item.node->left, item.level + 1};
//            S.push_back(item1);
//        }
//    }
//    return ans;
//}

void TreeNodeTest()
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
    
    sln.postorderTraverse(nodes);
    cout << endl;
    // sln.inorder(nodes);
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
    
    cout << sln.isBalanced(nodes) << endl;
}

void Test1()
{
    Solution sln;
    
    TreeNode nodes[] = {1, 2};
    nodes[0].right = nodes+1;
    cout << sln.isBalanced(nodes) << endl;
}

void Test2()
{
    Solution sln;
    
    TreeNode nodes[] = {1, 2, 3};
    nodes[0].right = nodes+1;
    nodes[1].right = nodes+2;
    cout << sln.isBalanced(nodes) << endl;
}



int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
