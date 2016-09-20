#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

template<class T>
T gcd(T m, T n) {
    if (m < n) return gcd(n, m);
    
    if (n == 0) return m;
    
    return gcd(n, m%n);
}


class Solution {
public:
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int s = 0;
        
        for (; (k = k%n); n -= k, s += k)
        {
            // Swap the last k elements with the first k elements.
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements
            // to the right by k steps.
            for (int i = 0; i < k; i++)
            {
                swap(nums[s+i], nums[n - k + s+i]);
            }
            
            // If n - k < k
            //     a0, ..., a(n-k), ..., a(k-1), ..., a(n-1)
            // --> a(n-k), ..., an,
            
        }
    }
    
    // Three reverses.
    void rotate_rev(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0 || (k = k%n) == 0) return;
        
        reverse(nums.begin(), nums.begin() + n-k);
        
        reverse(nums.begin()+n-k, nums.end());
        
        reverse(nums.begin(), nums.end());
    }
    
    void rotate1(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        
        k = k % n;
        if (k == 0) return;
        
        // if gcd(n, k) == g, n/g = d
        //  0*k, 1*k, ..., (d-1)*k must have distince remainders according to n.
        //  PROVE:
        //  if (d1 - d2) * k % n == 0, (0 <= d1 < d2 < d), then d1 - d2 must be a multiple of d,
        //           however, d1-d2 < d, so, d1-d2 == 0, which is confilict to our assumption.
        int g = gcd(n, k);
        for (int i = 0; i < g; ++i) {
            
            int prevIdx = i;
            int t = nums[i];
            
            int j = (i + n - k) % n;
            while (j != i) {
                nums[prevIdx] = nums[j];
                prevIdx = j;
                j = (j + n - k) % n;
            }
            nums[prevIdx] = t;
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
    vector<int> nums = {1, 2, 3,4, 5, 6};
    sln.rotate(nums, 3);
    printVector(nums);
}


void Test2()
{
    Solution sln;
    vector<int> nums = {1, 2, 3, 4, 5, 6,7, 8};
    sln.rotate(nums, 3);
    printVector(nums);
}

int main()
{
    Test0();
    Test2();
    
    return 0;
}
