#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        mAns.clear();
        
        restore(s, "", 0, 0);
        return mAns;
    }
    
private:
    
    void restore(const string &s, string ip, int i, int j) {
        if (i == 4) {
            if (j == s.length())
                mAns.push_back(ip);
            return;
        }
        if ((4-i) * 3 < s.length() - j)
            return;
        
        for (int k = 3; k > 0; --k) {
            string t = s.substr(j, k);
            
            if (t[0] == '0' && k > 1) continue;
            int tt = atoi(t.c_str());
            if (tt >= 256) continue;
            
            string x = ip;
            if (i > 0) x += ".";
            x += t;
            restore(s, x, i+1, j+k);
        }
    }
    vector<string> mAns;
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
    printVector(sln.restoreIpAddresses("2552551113"));
    
    printVector(sln.restoreIpAddresses("0000"));
    
    printVector(sln.restoreIpAddresses("10010001"));
}

int main()
{
    Test0();
    
    return 0;
}
