#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& a, vector<int>& b, int k) {
        int lowa = 0, higha = a.size() - 1, lowb = 0, highb = b.size() - 1;
        
        k = a.size() + b.size() - k;
        
        while (lowa < higha && lowb < highb) {
            int mida = (lowa + higha) / 2;
            int midb = (lowb + highb) / 2;
            
            if (a[mida] < b[midb]) {
                // (a[0], a[mida])     ---
                //                 (a[mida+1, a[sizea-1])
                //
                //      (b[0], b[midb])         \  (b[midb, b[sizeb-1])
                //        /
                if (k > mida + midb) {
                    lowa = mida + 1;
                    k -= mida + 1;
                } else {
                    highb = midb;
                }
            } else {
                if (k > mida + midb) {
                    lowb = midb + 1;
                    k -= midb + 1;
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
        
        // if (lowa == higha) {
            
            // b[lowb + k], b[lowb + k - 1] , a[lowa]
            if (b[lowb + k] <= a[lowa]) {
                return b[lowb + k];
            } else {
                if (k - 1 >= 0 && b[lowb+k-1] >= a[lowa]) {
                    return b[lowb+k-1];
                } else {
                    return a[lowa];
                }
            }
        //}
    }
private:
    void swap(int& a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
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
    
    vector<int> a = {1, 3, 4};
    vector<int> b = {2, 4, 6, 7};
    
    printf("%d\n", sln.findKthLargest(a, b, 1));
}

int main()
{
    Test0();
    
    return 0;
}
