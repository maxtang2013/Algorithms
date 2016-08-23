#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = (int)(nums1.size() + nums2.size());
        
        if (k % 2 == 1) {
            return findKthSmallest(nums1, nums2, k/2);
        } else {
            int m1 = findKthSmallest(nums1, nums2, k/2-1);
            int m2 = (double)findKthSmallest(nums1, nums2, k/2);
            // printf("m1=%d, m2=%d\n", m1, m2);
            return (m1 + (double)m2) / 2.0;
        }
    }
    
    // k is 1-based here.
    int findKthLargest(vector<int>& a, vector<int>& b, int k) {
        k = (int)(a.size() + b.size()) - k;
        return findKthSmallest(a, b, k);
    }
    
private:
    // k is 0-based for this method.
    // Assuming both array 'a' and 'b' are sorted ascendingly.
    int findKthSmallest(vector<int>& a, vector<int>& b, int k) {
        int lowa = 0, higha = (int)a.size() - 1, lowb = 0, highb = (int)b.size() - 1;
        if (a.empty()) return b[k];
        if (b.empty()) return a[k];
        
        while (lowa < higha && lowb < highb) {
            int mida = (lowa + higha) / 2;
            int midb = (lowb + highb) / 2;
            // printf("%d, %d) (%d, %d)\n", lowa, higha, lowb, highb);
            if (a[mida] <= b[midb]) {
                // (a[0], a[mida])     ---
                //                 (a[mida+1, a[sizea-1])
                //
                //      (b[0], b[midb])         \  (b[midb＋1］, b[sizeb-1])
                //        /
                if (k >= (mida - lowa + 1) + (midb - lowb + 1)) {
                    k -= (mida + 1 - lowa);
                    lowa = mida + 1;
                } else {
                    highb = midb;
                }
            } else {
                if (k >= (mida - lowa + 1) + (midb - lowb + 1)) {
                    k -= (midb + 1 - lowb);
                    lowb = midb + 1;
                } else {
                    higha = mida;
                }
            }
        }
        
        if (lowb == highb) {
            swap(lowa,lowb);
            swap(higha, highb);
            vector<int> c = a;
            a = b;
            b = c;
        }
        
        int ans = 0;
        
        // if (lowa == higha) {
        
        // b[lowb + k], b[lowb + k - 1] , a[lowa]
        
        if (k + lowb > highb) {
            
            if (b[highb] <= a[lowa]) ans = a[lowa];
            else ans = b[highb];
            
        } else if (b[lowb + k] <= a[lowa]) {
            ans = b[lowb + k];
        } else {
            if (k - 1 >= 0 && b[lowb+k-1] >= a[lowa]) {
                ans = b[lowb+k-1];
            } else {
                ans = a[lowa];
            }
        }
        //}
        
        return ans;
    }
 
    
    
private:
    void swap(int& a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

void Test0()
{
    Solution sln;
    
    vector<int> a = {1, 3, 4};
    vector<int> b = {2, 4, 6, 7};
    
    printf("%f\n", sln.findMedianSortedArrays(a, b));
}

void Test1()
{
    Solution sln;
    
    vector<int> a = {2};
    vector<int> b = {};
    
    printf("%f\n", sln.findMedianSortedArrays(a, b));
}

void Test2()
{
    Solution sln;
    
    vector<int> a = {3, 3, 3, 3};
    vector<int> b = {3, 3, 3, 3};
    
    printf("%f\n", sln.findMedianSortedArrays(a, b));
}

void Test3()
{
    Solution sln;
    
    vector<int> a = {3};
    vector<int> b = {3};
    
    printf("%f\n", sln.findMedianSortedArrays(a, b));
}

void Test4()
{
    Solution sln;
    
    vector<int> a = {1,1};
    vector<int> b = {1, 2};
    
    int x = sln.findKthLargest(a, b, 1);
    
    printf("%f\n", sln.findMedianSortedArrays(a, b));
    printf("%f\n", sln.findMedianSortedArrays(b, a));
}

void Test5()
{
    vector<int> a = {1,3};
    vector<int> b = {2};
    Solution sln;
    printf("%f\n", sln.findMedianSortedArrays(a, b));
}

int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}
