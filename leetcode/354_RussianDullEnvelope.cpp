#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


//You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//
//What is the maximum number of envelopes can you Russian doll? (put one inside other)
//
//Example:
//Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

struct Less {
    bool operator()(const pair<int,int>& a, const pair<int, int>&b) {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    }
};

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int, int>> dp;
        vector<int> temp(n);
        
        sort(envelopes.begin(), envelopes.end(), Less());
        dp.push_back(make_pair(0,0));
        
        for (int i = 0; i < n; ++i) {
            auto p = envelopes[i];
            int lo = 0, hi = dp.size();
            
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (dp[mid].second >= p.second) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            
            if (hi < dp.size()) {
                dp[hi] = p;
            } else {
                dp.push_back(p);
            }
        }
        
        return dp.size() - 1;
    }
    
    int maxEnvelopes_mine(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int, int>> dp;
        vector<int> temp(n);
        
        sort(envelopes.begin(), envelopes.end());
        dp.push_back(make_pair(0,0));
        
        int i = 0, j;
        
        while ( i < n ) {
            j = i;
            while (j < n && envelopes[j].first == envelopes[i].first) {
                if (envelopes[j].second > dp[dp.size()-1].second) {
                    dp.push_back(envelopes[j]);
                    break;
                }
                ++j;
            }
            
            j = i;
            while (j < n && envelopes[j].first == envelopes[i].first) {
                auto p = envelopes[j];
                
                int lo = 1, hi = dp.size();
                
                while (lo < hi) {
                    int mid=(lo+hi)/2;
                    if (dp[mid].second >= p.second) {
                        hi = mid;
                    } else {
                        lo = mid + 1;
                    }
                }
                
                temp[j] = hi;
                ++j;
            }
            
            j = i;
            while (j < n && envelopes[j].first == envelopes[i].first) {
                if (temp[j] < dp.size() && dp[temp[j]].second > envelopes[j].second) {
                    dp[temp[j]] = envelopes[j];
                }
                ++j;
            }
            
            i = j;
        }
        
        return dp.size() - 1;
    }
};

void Test0()
{
    Solution sln;
    vector<pair<int, int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    
    cout << sln.maxEnvelopes(envelopes) << endl;
}

void Test1()
{
    Solution sln;
    vector<pair<int, int>> envelopes = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
    
    cout << sln.maxEnvelopes(envelopes) << endl;
}

void Test2() {
    Solution sln;
    vector<pair<int, int>> envelopes = {{30,50},{12,2},{3,4},{12,15}};
    cout << sln.maxEnvelopes(envelopes) << endl;
}

void Test3() {
    Solution sln;
    vector<pair<int, int>> envelopes = {{1,15},{2,200},{3,5},{3,6},{3,10},{7,6},{7,8},{7,18},{7,20},{7,100},{17,3},{17,30},{17,45},{17,45}};
    cout << sln.maxEnvelopes(envelopes) << endl;
}
void Test4() {
    Solution sln;
    vector<pair<int, int>> envelopes = {{1,3},{1,13},{1,14},{2,10},{2,16},{3,12},{4,6},{4,16},{5,7},{7,7},{8,7},{10,3},{11,2},{13,11},{13,13},{13,13},{14,16},{17,2},{20,18}};
    cout << sln.maxEnvelopes(envelopes) << endl;
}

int main()
{
//    Test0();
//    Test1();
//    Test2();
//    Test3();
    Test4();
    
    return 0;
}
