#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        // A, C, G, T
        vector<string> ans;
        if (s.length() < 10) return ans;
        
        vector<int> cnt(1<<21);
        
        int n = (int) s.length();
        int x = 0;
        for (int i = 0; i < 9; ++i) {
            x = (x << 2) | ((s[i] - 'A' + 1) % 5);
        }
        
        for (int i = 9; i < n; ++i) {
            x = ((x << 2) | ((s[i] - 'A' + 1) % 5)) & 0xfffff;
            if (cnt[x]++ == 1) {
                ans.push_back(s.substr(i-9, 10));
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
    cout << endl;
}

void Test0()
{
    Solution sln;
    printVector(sln.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")) ;
}

int main()
{
    Test0();
    
    cout << (int) ('C' - 'A') << " " << (int) ('G' - 'A') << " " << (int) ('T' - 'A') << endl;
    
    return 0;
}
