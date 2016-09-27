#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

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

class Solution {
public:
    
    void sort (vector<int>& nums) {
        sort (nums, 0, (int) nums.size());
    }
    
    void sort(vector<int>& nums, int start, int end) {
        if (end - 1 <= start) return;
        
        int i = start, j = start, k = end - 1;
        int pivot = nums[end - 1];
        
        // Lomuto partition.
        while (j <= k) {
            if (nums[j] < pivot) {
                swap(nums[i++], nums[j++]);
            } else if (nums[j] > pivot) {
                swap(nums[j], nums[k--]);
            } else {
                ++j;
            }
        }
        
        sort (nums, start, i);
        sort (nums, i+1, end);
    }
    
    void wiggleSort(vector<int>& nums) {
        
        int n = (int) nums.size();
        nth_element(nums.begin(), nums.begin() + (n/2), nums.end());
        
        int mid = nums[n/2];
        
#define A(i) nums[ (1+2*(i))%(n|1) ]
        
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
//            printVector(nums);
            if (A(j) > mid) {
                swap(A(i++), A(j++));
            }
            else if (A(j) < mid) {
                swap(A(j), A(k--));
            } else {
                j++;
            }
        }
        
        // printVector(nums);
    }
};



void Test0()
{
    Solution sln;
    vector<int> nums = { 7, 8, 0, 6, 1, 2, 3, 4, 5, 8, 6, 9};
    sln.wiggleSort(nums);
    
    printVector(nums);
    
    cout << "Sort:\n";
    sln.sort(nums);
    printVector(nums);
}

int main()
{
    Test0();
    
    return 0;
}
