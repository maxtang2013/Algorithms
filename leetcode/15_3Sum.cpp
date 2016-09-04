#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = (int) nums.size();
        
        sort(nums.begin(), nums.end());
        
        int x = 0;
        for (int i = 0; i < n-2; ++i) {
           
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            x = nums[i];
            
            if (x + nums[n-1] + nums[n-2] < 0) continue;
            if (x + nums[i + 1] + nums[i + 2] > 0)
                break;
            
            for (int j = i + 1; j < n-1; ++j) {
                
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                x = nums[i] + nums[j];
                if (x + nums[n-1] < 0) continue;
                if (x + nums[j + 1] > 0)
                    break;
                
                int low = j + 1, high = n - 1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (nums[mid] == -x) {
                        vector<int> item(3);
                        item[0] = nums[i];
                        item[1] = nums[j];
                        item[2] = -x;
                        ans.push_back(item);
                        break;
                    } else if (nums[mid] < -x) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                
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

void printBoard(vector<vector<int>> &ans) {
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

void Test0()
{
    Solution sln;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> ans = sln.threeSum(nums);
    
    printBoard(ans);
}

void Test1()
{
    Solution sln;
    vector<int> nums = {-1,-3,0,1,2,-1,-4};
    
    vector<vector<int>> ans = sln.threeSum(nums);
    
    printBoard(ans);
}

int main()
{
    Test0();
    Test1();
    
    return 0;
}
