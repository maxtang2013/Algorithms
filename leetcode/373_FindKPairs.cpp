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
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0, j = 0, n = (int) nums1.size(), m = (int) nums2.size();
        vector<pair<int, int> > ans;
        vector<int> index(n, 0);
        
        k = min(k, m * n);
        
        for (i = 0; i < k; ++i) {
            int minVal = INT_MAX;
            int minIdx = -1;
            for (j = 0; j < n; ++j) {
                if (index[j] >= m) continue;
                
                int val = nums1[j] + nums2[index[j]];
                if (val < minVal) {
                    minVal = val;
                    minIdx = j;
                }
            }
            ans.push_back(make_pair(nums1[minIdx], nums2[index[minIdx]]));
            ++index[minIdx];
        }
        
        return ans;
    }
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
    vector<int> n1 = {1, 7, 11}, n2 = {2,4,6};
    printVector(sln.kSmallestPairs(n1, n2, 3));
    
//  Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
//  Return: [1,2],[1,4],[1,6]
}

int main()
{
    Test0();
    
    return 0;
}
