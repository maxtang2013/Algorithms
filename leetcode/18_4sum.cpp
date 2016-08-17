#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

struct Entry {
    int x, y;
    int val;
};

struct Comparator {
    bool operator()(const Entry& e1, const Entry& e2)
    {
        return e1.val > e2.val;
    }
};
// priority_queue<Entry, vector<Entry>, Comparator> Q;

class Solution {
public:
    
#define PASS_SAME_ELEMENT(index, arr, val, len) \
    while (index < len && arr[++index] == val);
    
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        const int n = (int) nums.size();
     
        mTarget = target;
        mResult.clear();
        
        if (n == 0) return mResult;
        
        mNums = nums;
        sort (mNums.begin(), mNums.end());
        mLargest = mNums[n-1];
        
        vector<int> quadruplet(4, 0);
        
//        int i1, i2, i3, i4;
//        int remain = target;
//
//        for (i1 = 0; i1 < n - 3; )
//        {
//            int val1 = mNums[i1];
//            
//            if ((mLargest << 2) < remain || (val1 << 2) > remain)
//                break;
//            
//            remain -= val1;
//            
//            for (i2 = i1 + 1; i2 < n - 2; )
//            {
//                int val2 = mNums[i2];
//                
//                if (mLargest * 3 < remain || val2 * 3 > remain) break;
//                
//                remain -= val2;
//                
//                for (i3 = i2 + 1; i3 < n - 1; )
//                {
//                    int val3 = mNums[i3];
//                    
//                    if ( (mLargest<<1) < remain || (val3<<1) > remain) break;
//                    
//                    remain -= val3;
//                    
//                    for (i4 = i3 + 1; i4 < n; )
//                    {
//                        int val4 = mNums[i4];
//                        
//                        if (val4 > remain || mLargest < remain) break;
//                        
//                        if (val4 == remain)
//                        {
//                            quadruplet[0] = val1;
//                            quadruplet[1] = val2;
//                            quadruplet[2] = val3;
//                            quadruplet[3] = val4;
//                            
//                            mResult.push_back(quadruplet);
//                        }
//                        
//                        PASS_SAME_ELEMENT(i4, mNums, val4, n);
//                    }
//                    PASS_SAME_ELEMENT(i3, mNums, val3, n);
//                    remain += val3;
//                }
//                
//                PASS_SAME_ELEMENT(i2, mNums, val2, n);
//                remain += val2;
//            }
//            
//            PASS_SAME_ELEMENT(i1, mNums, val1, n);
//            remain += val1;
//        }
        
        traverse(quadruplet, n, 0, 4, target);
        
        return mResult;
    }
private:
    void traverse(vector<int> &quadruplet, int n, int i, int k, int target)
    {
        if (k > n - i) return;
        
        if (target > k * mLargest || target < k * mNums[i])
            return;
        
        if (k == 1)
        {
            if (std::binary_search(mNums.begin(), mNums.end(), target))
            {
                quadruplet[0] = target;
                mResult.push_back(quadruplet);
            }
            return;
        }
        
        int j = i;
        while ( j < n )
        {
            int val = mNums[j];
            quadruplet[k-1] = val;
            
            traverse(quadruplet, n, j+1, k-1, target - val);
            
            while (j < n && mNums[++j] == val);
        }
    }
    
private:
    vector<vector<int>> mResult;
    vector<int> mNums;
    int mTarget;
    int mLargest;
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

int getLastBit(int n)
{
    //    Equavilent:
    //    int mask = 0;
    //    for (i = 0; i < 32; ++i)
    //    {
    //        mask = 1 << i;
    //        if (bits & mask)
    //        {
    //            break;
    //        }
    //    }
    //    return mask;
    
    return n & (-n);
}

void printBits(int n)
{
//    for (int i = 31; i >= 0; --i)
//    {
//        if (n & (1<<i)) std::cout << "1";
//        else std::cout << "0";
//    }
//    std::cout << "\n";
    
    std::bitset<32> bits(n);
    std::cout << bits << "\n";
}

int countBits(int n)
{
    int cnt = 0;
    while (n)
    {
        ++cnt;
        n = n & (n - 1);
    }
    return cnt;
}

void Test0()
{
    Solution sln;
    vector<int> nums1 = {-498,-492,-473,-455,-441,-412,-390,-378,-365,-359,-358,-326,-311,-305,-277,-265,-264,-256,-254,-240,-237,-234,-222,-211,-203,-201,-187,-172,-164,-134,-131,-91,-84,-55,-54,-52,-50,-27,-23,-4,0,4,20,39,45,53,53,55,60,82,88,89,89,98,101,111,134,136,209,214,220,221,224,254,281,288,289,301,304,308,318,321,342,348,354,360,383,388,410,423,442,455,457,471,488,488};
    
    
    vector<vector<int> > result = sln.fourSum(nums1, -2808);
    
    for (vector<int> row : result)
    {
        printVector(row);
    }
}

void Test1()
{
    Solution sln;
    
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int> > result = sln.fourSum(nums, 0);
    
    for (vector<int> row : result)
    {
        printVector(row);
    }
}

void Test2()
{
    Solution sln;
    
    vector<int> nums = { 91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245};
    
    vector<vector<int> > result = sln.fourSum(nums, -236727523);
    
    for (vector<int> row : result)
    {
        printVector(row);
    }
    
}
void Test3()
{
    Solution sln;
    vector<int> nums = {};
    vector<vector<int> > result = sln.fourSum(nums, -236727523);
    
    for (vector<int> row : result)
    {
        printVector(row);
    }
}
int main()
{
    // Test0();
    // Test1();
    Test2();
    Test3();
    
    return 0;
}
