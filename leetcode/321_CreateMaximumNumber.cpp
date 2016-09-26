#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

template<typename T>
void printVector(const vector<T>& list)
{
    int len = (int)list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << list[i];
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
    cout << endl;
}

class List {
public:
    List(vector<int>& num) {
        mSize = (int) num.size();
        mFiristPosition.resize(10);
        
        for (int i =  0; i < 10; ++i)
            mFiristPosition[i].resize(mSize+1);
        
        for (int d = 0; d < 10; ++d) {
            mFiristPosition[d][mSize] = INT_MAX;
            for (int i = mSize - 1; i >= 0; --i) {
                if (num[i] == d) mFiristPosition[d][i] = i;
                else mFiristPosition[d][i] = mFiristPosition[d][i+1];
            }
        }
    }
    
    pair<int, int> getMaxDigit(int startIndex, int seqLen) {
        for (int d = 9; d >= 0; --d) {
            if (mSize - mFiristPosition[d][startIndex] >= seqLen) {
                return make_pair(d, mFiristPosition[d][startIndex] + 1);
            }
        }
        return make_pair(-1, INT_MAX);
    }
    
private:
    vector<vector<int>> mFiristPosition;
    int mSize;
};

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = (int)nums1.size(), n = (int)nums2.size();
        
        List l1(nums1), l2(nums2);
        vector<int> num(k, 0);
        vector<int> paired(m+1, 0);
        
        for (int t = 0; t < k; ++t) {
            int maxDigit = -1;
            
            for (int x = 0; x <= m; ++x) {
                int y = paired[x];
                if ( y == INT_MAX ) continue;
                
                auto m1 = l1.getMaxDigit(x, k - t - n + y);
                maxDigit = max(m1.first, maxDigit);
                
                auto m2 = l2.getMaxDigit(y, k - t - m + x);
                maxDigit = max(m2.first, maxDigit);
            }
            
            num[t] = maxDigit;
            
            vector<int> newPaired(m+1, INT_MAX);
            for (int x = 0; x <= m; ++x) {
                int y = paired[x];
                if ( y == INT_MAX ) continue;
                
                auto m1 = l1.getMaxDigit(x, k - t - n + y);
                if (m1.first == maxDigit) {
                    newPaired[m1.second] = min(y, newPaired[m1.second]);
                    // newPaired[m1.second] = y;
                }
                
                auto m2 = l2.getMaxDigit(y, k - t - m + x);
                if (m2.first == maxDigit) newPaired[x] = min( m2.second, newPaired[x] ) ;
                // if (m2.first == maxDigit) newPaired[x] = m2.second;
            }
            paired = newPaired;
        }
        
        return num;
    }
    
    vector<int> maxNumber_2(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> ans(k, 0);
        for (int i = 0; i <= k; ++i) {
            if (i > m || k - i > n) continue;
            vector<int> a = maxNumber(nums1, i);
            vector<int> b = maxNumber(nums2, k-i);
            vector<int> merged = merge(a, b);
            if (greater(merged, ans)) ans = merged;
        }
        return ans;
    }
    
private:
    vector<int> maxNumber(vector<int>& nums, int k) {
        int n = (int) nums.size();
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            while (!S.empty() && S.size() + n - i > k && S.back() < nums[i])
                S.pop_back();
            
            S.push_back(nums[i]);
        }
        while (S.size() > k) S.pop_back();
        return S;
    }
    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int m = a.size(), n = b.size();
        ostringstream str_a, str_b;
        for (int i = 0; i < m; ++i) str_a << a[i];
        for (int i = 0; i < n; ++i) str_b << b[i];
        string stra = str_a.str(), strb = str_b.str();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (stra.substr(i) .compare( strb.substr(j) ) > 0) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }
        while (i < m) ans.push_back(a[i++]);
        while (j < n) ans.push_back(b[j++]);
        return ans;
    }
    bool greater(const vector<int> &a, const vector<int> &b) {
        int k = a.size();
        for (int i = 0; i < k; ++i) {
            if (a[i] > b[i]) return true;
            if (a[i] < b[i]) return false;
        }
        return false;
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums1 = {3, 4, 9, 6, 8, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    
    printVector(sln.maxNumber_2(nums1, nums2, 5));
}

void Test1()
{
    Solution sln;
    vector<int> nums1 = {6,7};
    vector<int> nums2 = {6,0,4};
    printVector(sln.maxNumber_2(nums1, nums2, 5));
}

void Test2() {
    Solution sln;
    vector<int> nums1 = {8,9};
    vector<int> nums2 = {3,9};
    
    printVector(sln.maxNumber_2(nums1, nums2, 3));
}

void Test3() {
    Solution sln;
    vector<int> nums1 = {3,4,6,5};
    vector<int> nums2 = {9,1,2,5,8,3};
    printVector(sln.maxNumber_2(nums1, nums2, 5));
}

void Test4() {
    Solution sln;
    vector<int> nums1 = {8,9,7,3,5,9,1,0,8,5,3,0,9,2,7,4,8,9,8,1,0,2,0,2,7,2,3,5,4,7,4,1,4,0,1,4,2,1,3,1,5,3,9,3,9,0,1,7,0,6,1,8,5,6,6,5,0,4,7,2,9,2,2,7,6,2,9,2,3,5,7,4,7,0,1,8,3,6,6,3,0,8,5,3,0,3,7,3,0,9,8,5,1,9,5,0,7,9,6,8,5,1,9,6,5,8,2,3,7,1,0,1,4,3,4,4,2,4,0,8,4,6,5,5,7,6,9,0,8,4,6,1,6,7,2,0,1,1,8,2,6,4,0,5,5,2,6,1,6,4,7,1,7,2,2,9,8,9,1,0,5,5,9,7,7,8,8,3,3,8,9,3,7,5,3,6,1,0,1,0,9,3,7,8,4,0,3,5,8,1,0,5,7,2,8,4,9,5,6,8,1,1,8,7,3,2,3,4,8,7,9,9,7,8,5,2,2,7,1,9,1,5,5,1,3,5,9,0,5,2,9,4,2,8,7,3,9,4,7,4,8,7,5,0,9,9,7,9,3,8,0,9,5,3,0,0,3,0,4,9,0,9,1,6,0,2,0,5,2,2,6,0,0,9,6,3,4,1,2,0,8,3,6,6,9,0,2,1,6,9,2,4,9,0,8,3,9,0,5,4,5,4,6,1,2,5,2,2,1,7,3,8,1,1,6,8,8,1,8,5,6,1,3,0,1,3,5,6,5,0,6,4,2,8,6,0,3,7,9,5,5,9,8,0,4,8,6,0,8,6,6,1,6,2,7,1,0,2,2,4,0,0,0,4,6,5,5,4,0,1,5,8,3,2,0,9,7,6,2,6,9,9,9,7,1,4,6,2,8,2,5,3,4,5,2,4,4,4,7,2,2,5,3,2,8,2,2,4,9,8,0,9,8,7,6,2,6,7,5,4,7,5,1,0,5,7,8,7,7,8,9,7,0,3,7,7,4,7,2,0,4,1,1,9,1,7,5,0,5,6,6,1,0,6,9,4,2,8,0,5,1,9,8,4,0,3,1,2,4,2,1,8,9,5,9,6,5,3,1,8,9,0,9,8,3,0,9,4,1,1,6,0,5,9,0,8,3,7,8,5};
    vector<int> nums2 = {7,8,4,1,9,4,2,6,5,2,1,2,8,9,3,9,9,5,4,4,2,9,2,0,5,9,4,2,1,7,2,5,1,2,0,0,5,3,1,1,7,2,3,3,2,8,2,0,1,4,5,1,0,0,7,7,9,6,3,8,0,1,5,8,3,2,3,6,4,2,6,3,6,7,6,6,9,5,4,3,2,7,6,3,1,8,7,5,7,8,1,6,0,7,3,0,4,4,4,9,6,3,1,0,3,7,3,6,1,0,0,2,5,7,2,9,6,6,2,6,8,1,9,7,8,8,9,5,1,1,4,2,0,1,3,6,7,8,7,0,5,6,0,1,7,9,6,4,8,6,7,0,2,3,2,7,6,0,5,0,9,0,3,3,8,5,0,9,3,8,0,1,3,1,8,1,8,1,1,7,5,7,4,1,0,0,0,8,9,5,7,8,9,2,8,3,0,3,4,9,8,1,7,2,3,8,3,5,3,1,4,7,7,5,4,9,2,6,2,6,4,0,0,2,8,3,3,0,9,1,6,8,3,1,7,0,7,1,5,8,3,2,5,1,1,0,3,1,4,6,3,6,2,8,6,7,2,9,5,9,1,6,0,5,4,8,6,6,9,4,0,5,8,7,0,8,9,7,3,9,0,1,0,6,2,7,3,3,2,3,3,6,3,0,8,0,0,5,2,1,0,7,5,0,3,2,6,0,5,4,9,6,7,1,0,4,0,9,6,8,3,1,2,5,0,1,0,6,8,6,6,8,8,2,4,5,0,0,8,0,5,6,2,2,5,6,3,7,7,8,4,8,4,8,9,1,6,8,9,9,0,4,0,5,5,4,9,6,7,7,9,0,5,0,9,2,5,2,9,8,9,7,6,8,6,9,2,9,1,6,0,2,7,4,4,5,3,4,5,5,5,0,8,1,3,8,3,0,8,5,7,6,8,7,8,9,7,0,8,4,0,7,0,9,5,8,2,0,8,7,0,3,1,8,1,7,1,6,9,7,9,7,2,6,3,0,5,3,6,0,5,9,3,9,1,1,0,0,8,1,4,3,0,4,3,7,7,7,4,6,4,0,0,5,7,3,2,8,5,1,4,5,8,5,6,7,5,7,3,3,9,6,8,1,5,1,1,1,0,3};
    printVector(sln.maxNumber_2(nums1, nums2, 500));
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    Test4();
    
    return 0;
}
