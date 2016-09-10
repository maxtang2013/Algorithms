#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

class UnionFind {
public:
    
    UnionFind(int N) {
        id = new int[N];
        sz = new int[N];
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }
    
    ~UnionFind() {
        delete []id;
        delete []sz;
    }
    
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        
        if (i == j) return;
        
        if (sz[i] > sz[j]) {
            id[j] = i;
            sz[i] += sz[j];
        } else {
            id[i] = j;
            sz[j] += sz[i];
        }
    }
    
    int getSize(int i) {
        int r = root(i);
        return sz[r];
    }
    
private:
    
    int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    
private:
    
    int* id;
    int* sz;
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int, pair<int, int>> upper;
        
        int n = (int) nums.size();
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            unordered_map<int, pair<int, int>>::iterator it = upper.find(val);
            if (it != upper.end()) continue;
            
            it = upper.find(val - 1);
            unordered_map<int, pair<int, int>>::iterator it2 = upper.find(val + 1);
            
            int l, r;
            
            if (it != upper.end() && it2 != upper.end()) {
                l = it->second.first;
                r = it2->second.second;
            }
            else if (it != upper.end()) {
                l = it->second.first;
                r = val;
            } else if (it2 != upper.end()) {
                l = val;
                r = it2->second.second;
            } else {
                l = r = val;
            }
            
            pair<int, int> p = make_pair(l, r);
            upper[l] = p;
            upper[r] = p;
            upper[val] = p;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
    
    int longestConsecutive_UF(vector<int>& nums) {
        int n = (int)nums.size();
        UnionFind uf(n);
        
        unordered_map<int, int> m;
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            
            if (m.count(val)) continue;
            m[val] = i;
            
            if (m.count(val - 1)) {
                uf.unite(i, m[val - 1]);
            }
            if (m.count(val + 1)) {
                uf.unite(i, m[val + 1]);
            }
        }
        
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, uf.getSize(i));
        }
        return ans;
    }
};

void Test0()
{
    Solution sln;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sln.longestConsecutive(nums) << endl;
}

int main()
{
    Test0();
    
    return 0;
}
