#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;


struct Comp {
    bool operator()(const string& s1, const string& s2) {
        int m = s1.length(), n = s2.length();
        int longer = m + n;
       
        for (int i = 0; i < longer; ++i) {
            char c1, c2;
            if (i < m) c1 = s1[i];
            else c1 = s2[i-m];
            
            if (i < n) c2 = s2[i];
            else c2 = s1[i-n];
            
            if (c1 < c2) return true;
            if (c1 > c2) return false;
        }
        
        return false;
    }
};


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = (int) nums.size();
        vector<string> ns(n);
        for (int i = 0; i < n; ++i) {
            ostringstream s;
            s << nums[i];
            ns[i] = s.str();
        }
        
        sort (ns.begin(), ns.end(), Comp());
        
        for (int i = 0; i < n; ++i) cout << ns[i] << endl;
        
        string ans;
        for (int i = n-1; i >= 0; --i) {
            ans += ns[i];
        }
        
        int i = 0;
        
        for (i = 0; i < ans.length(); ++i)
            if (ans[i] != '0') break;
        
        if (i == ans.length()) ans = "0";
        else ans = ans.substr(i);
        
        return ans;
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums = {3, 33, 30, 31, 332, 1, 2, 5, 8, 124, 3321, 4321};
    cout << sln.largestNumber(nums) << endl;
}

void Test1()
{
    Solution sln;
    vector<int> nums = {1};
    cout << sln.largestNumber(nums) << endl;
}

void Test2()
{
    Solution sln;
    vector<int> nums = {121, 12};
    cout << sln.largestNumber(nums) << endl;
}

void Test3()
{
    Solution sln;
    vector<int> nums = {12, 121};
    cout << sln.largestNumber(nums) << endl;
}


class A
{
    virtual void a()
    {
    }
};
class A1
{
    virtual void a()
    {
    }
};
class B : public A , virtual public A1
{
};

int main()
{
//    Test0();
//    Test1();
    Test2();
    Test3();
    
    // "1313451" vs "1313145"
    
    cout << sizeof(B) << endl;
    cout << sizeof(A) << endl;
    
    return 0;
}
