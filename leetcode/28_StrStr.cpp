#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

/**
 *  K.M.P algorithm
 *
 **/
class Solution {
public:
    int strStr(string str, string pattern) {
        int size_pattern = (int) pattern.size();
        int size_str = (int) str.size();
        vector<int> T(size_pattern, -1);
        
        if (size_pattern == 0) return 0;
        
        generateNext(pattern, T);
        
        int m = 0;
        int i = 0;
        while ( m <= size_str - size_pattern ) {
            if (str[m + i] == pattern[i]) {
                if (++i == size_pattern) return m;
            } else {
                m = m + i - T[i];
                i = T[i] == -1 ? 0 : T[i];
            }
        }
        
        return -1;
    }
    
private:
    void generateNext(string pattern, vector<int> &T) {
        int i = 0, j = -1;
        int size_p = (int)pattern.length();
        
        T[0] = -1;
        while ( i < size_p - 1 ) {
            if (j == -1 || pattern[i] == pattern[j]) {
                T[++i] = ++j; // 1
            } else {
                j = T[j];     // 2
            }
        }
        // To prove the algorithm is O(size_p), notice that statement 2 will not be excueted more than statement 1.
        // Say, for some period, j increased successively to K, which means statement 1 has been executed K+1 times.
        // Then it will need no more than K + 1 times of execution of statement 2 to get j to -1 because T[j] < j is
        // always true.
        // Statement 1 will be executed exactly size_p times, so the algorithm is O(size_p).
    }
};

void Test0()
{
    Solution sln;
    printf("%d\n", sln.strStr("mississippi", "a"));
    
    printf("%d\n", sln.strStr("mississippi", "issi"));
    
    
    printf("%d\n", sln.strStr("mississippi", "si"));
    
}

int main()
{
    Test0();
    
    return 0;
}
