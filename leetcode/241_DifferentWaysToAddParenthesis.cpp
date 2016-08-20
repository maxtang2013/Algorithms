#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <map>

using namespace std;

namespace T241
{
    class Functor {
    public:
        virtual ~Functor(){}
        virtual int apply(int a, int b) = 0;
    };
    
    class Add : public Functor {
public:
    int apply(int a, int b)
    {
        return a + b;
    }
};
    class Sub : public Functor{
    public:
        int apply(int a, int b)
        {
            return a - b;
        }
    };
    class Mul : public Functor {
    public:
        int apply(int a, int b)
        {
            return a * b;
        }
    };
    
class Solution {
public:
    Solution()
    {
        func['+'] = new Add();
        func['-'] = new Sub();
        func['*'] = new Mul();
    }
    ~Solution()
    {
        delete func['+'];
        delete func['-'];
        delete func['*'];
    }
    vector<int> diffWaysToCompute(string s) {
        int n = s.length();
        int i;
        vector<int> ans;
        bool found = false;
        int num = 0;
        for (i = 0; i < n; ++i)
        {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*')
            {
                vector<int> pre = diffWaysToCompute(s.substr(0, i));
                vector<int> post = diffWaysToCompute(s.substr(i+1));
                
                for (int a : pre)
                {
                    for (int b : post)
                    {
                        ans.push_back(func[s[i]]->apply(a, b));
                    }
                }
                found = true;
            }
            else
            {
                num = num * 10 + (s[i] - '0');
            }
        }
        
        if (!found) ans.push_back(num);
        
        return ans;
    }
    
    std::map<char, Functor*> func;
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
    printf("\n");
}

void Test0()
{
    Solution sln;
    printVector(sln.diffWaysToCompute("2-1-1"));
}

void Test1()
{
    Solution sln;
    printVector(sln.diffWaysToCompute("2*3-4*5"));
}
void Test2()
{
    Solution sln;
    printVector(sln.diffWaysToCompute(""));
}
void Test3()
{
    Solution sln;
    printVector(sln.diffWaysToCompute("1"));
}

void Test4()
{
    Solution sln;
    printVector(sln.diffWaysToCompute("1-100-2147483647+360"));
}

}
using namespace T241;

int main()
{
    //Test0();
    Test1();
    Test2();
    Test3();
    Test4();
    
    
    return 0;
}
