#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0, k = 0;
        
        for (i = m + n - 1; i >= n; --i) {
            nums1[i] = nums1[i-n];
        }
        
        i = n;
        j = 0;
        while (k < m + n) {
            if (j < n && (i==m+n || nums1[i] > nums2[j])) {
                nums1[k++] = nums2[j++];
            } else {
                nums1[k++] = nums1[i++];
            }
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
    cout << endl;
}

void Test0()
{
    Solution sln;
    vector<int> nums1 = {1, 2, 3, 4, 5, 7, 9, 11};
    for (int i = 0; i < 5; ++i) nums1.push_back(0);
    vector<int> nums2 = {2, 3, 4, 6, 8};
    
    sln.merge(nums1, 8, nums2, 5);
    
    printVector(nums1);
}
void Test1()
{
    Solution sln;
    vector<int> nums1 = {1};
    vector<int> nums2 = {};
    
    sln.merge(nums1, 1, nums2, 0);
    
    printVector(nums1);
}

void Test2()
{
    Solution sln;
    vector<int> nums1 = {0, 0, 0, 0, 0};
    vector<int> nums2 = {1, 2, 3, 4, 5};
    
    sln.merge(nums1, 0, nums2, 5);
    
    printVector(nums1);
}

int main()
{
    Test0();
    Test1();
    Test2();
    
    return 0;
}
