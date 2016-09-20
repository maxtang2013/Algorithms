#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        mAdj.resize(numCourses);
        mInDegree.resize(numCourses, 0);
        mVisited.resize(numCourses, false);
        
        vector<int> S;
        
        for (auto p : prerequisites) {
            mAdj[p.second].push_back(p.first);
            mInDegree[p.first]++;
        }
        
        for (int v = 0; v < numCourses; ++v) {
            if (mInDegree[v] == 0) {
                S.push_back(v);
            }
        }
        
        int n = numCourses;
        while ( !S.empty() ) {
            int v = S.back();
            S.pop_back();
            --n;

            for (int u : mAdj[v]) {
                if (--mInDegree[u] == 0)
                    S.push_back(u);
            }
        }
        return n == 0;
    }
    
    bool mHasCircle;
    vector<bool> mVisited;
    vector<int> mInDegree;
    vector<vector<int>> mAdj;
};

void Test0()
{
    Solution sln;
    vector<pair<int, int>> edges = {{1, 0}};
    cout << sln.canFinish(2, edges) << endl;
}

void Test1()
{
    Solution sln;
    vector<pair<int, int>> edges = {{1, 0}, {0, 1}};
    cout << sln.canFinish(2, edges) << endl;
}

void Test2()
{
    Solution sln;
    vector<pair<int, int>> edges = {{1, 0}, {1, 2}};
    cout << sln.canFinish(3, edges) << endl;
}

void Test3() {
    Solution sln;
    vector<pair<int, int>> edges = {{0,1},{0,2},{1,2}};
    cout << sln.canFinish(3, edges) << endl;
}
int main()
{
    Test0();
    Test1();
    Test2();
    Test3();
    
    return 0;
}
