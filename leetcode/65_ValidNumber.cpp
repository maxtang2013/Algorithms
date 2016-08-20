#include <iostream>
#include <string>

// using namespace std;

class Solution {

public:
    bool isNumber(std::string s) {
        return false;
    }

    bool canConstruct(std::string ransomNote, std::string magazine) {
        int count1[NUM_CHAR] = {0};
        int count2[NUM_CHAR] = {0};
        int i;
        int len1 = ransomNote.length();
        int len2 = magazine.length();
        
        for (i = 0; i < len1; ++i)
        {
            count1[ransomNote[i]]++;
        }
        
        for (i = 0; i < len2; ++i)
            count2[magazine[i]]++;
        
        for (i = 0; i < NUM_CHAR; ++i)
            if (count2[i] < count1[i])
                return false;
        
        return true;
    }
    
private:
    
    bool isNumberWithoutExp(std::string s)
    {
        return false;
    }
    
    const static int NUM_CHAR = 256;
    
};

int main()
{
    Solution sln;
    if (!sln.canConstruct("a", "b"))
        std::cout<<"Case 1 passed.\n";
    
    if (!sln.canConstruct("aa", "ab"))
        std::cout <<"Case 2 passed.\n";
    
    if (sln.canConstruct("aa", "aab"))
        std::cout << "case 3 passed\n";
    return 0;
}