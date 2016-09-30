#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

//Given a non-empty array of integers, return the k most frequent elements.
//
//For example,
//Given [1,1,1,2,2,3] and k = 2, return [1,2].

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int x : nums){
            freq[x]++;
            maxFreq=max(maxFreq, freq[x]);
        }
        vector<vector<int>> freqBucket(maxFreq+1);
        
        for (auto p : freq) {
            freqBucket[p.second].push_back(p.first);
        }
        
        vector<int> ans;
        
        for (int i = maxFreq; k > 0 && i > 0; --i) {
            int m = freqBucket[i].size();
            for (int j = 0; k>0 && j < m; ++j) {
                ans.push_back(freqBucket[i][j]);
                --k;
            }
        }
        return ans;
    }
};

template<typename T>
void printVector(const vector<T>& list)
{
    int len = (int)list.size();
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
    vector<int> nums = {1,1,1,2,2,3};
    printVector(sln.topKFrequent(nums, 2));
}

int main()
{
    Test0();
    
    return 0;
}
