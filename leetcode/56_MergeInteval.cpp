#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Comp {
    bool operator()(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
};
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        if (intervals.empty()) return intervals;
        
        sort( intervals.begin(), intervals.end(), Comp() );
        
        vector<Interval> ans;
        
        int start = intervals[0].start;
        int end = intervals[0].end;
        int n = (int) intervals.size();
        int i = 1;
        
        while (i < n) {
            if (intervals[i].start > end) {
                Interval newInteval(start, end);
                ans.push_back(newInteval);
                
                start = intervals[i].start;
                end = intervals[i].end;
            } else {
                end = max(end, intervals[i].end);
            }
            ++i;
        }
        
        Interval newInteval(start, end);
        ans.push_back(newInteval);
        
        return ans;
    }
    
    // Intervals are non-overlapping.
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = (int) intervals.size();
        
        int lo = 0, hi = n;
        int start = newInterval.start, end = newInterval.end;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            
            Interval &i = intervals[mid];
            if (i.end < start) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        if (lo < n && intervals[lo].end < start) ++lo;
        
        if (lo < n) {
            
            if (end < intervals[lo].start) {
                intervals.insert(intervals.begin() + lo, newInterval);
            } else {
                intervals[lo].start = min(start, intervals[lo].start);
                end = max(end, intervals[lo].end);
                
                // Can use binary search to boost this part.
                int removeFrom = lo + 1, removeTo = lo + 1;
                int i = lo + 1;
                while (i < n && intervals[i].start <= end) {
                    ++removeTo;
                    end = max(end, intervals[i].end);
                    ++i;
                }
                
                intervals[lo].end = end;
                
                // O(n)
                intervals.erase(intervals.begin() + removeFrom, intervals.begin() + removeTo);
            }
        } else {
            intervals.push_back(newInterval);
        }
        
        return intervals;
    }
};
template<typename T>
void printVector(const vector<T>& list)
{
    int len = list.size();
    for (int i = 0; i < len; ++i)
    {
        std::cout << "(" << list[i].start << ", " << list[i].end << ")";
        if (i < len - 1) std::cout << " ";
        else std::cout << "\n";
    }
    cout << endl;
}

void Test0()
{
    Solution sln;
    vector<Interval> intevals = {
        {1,3}, {2,6}, {8, 10}, {15, 18}
    };
    
    printVector(sln.merge(intevals));
}

void TestInsert1()
{
    Solution sln;
    vector<Interval> intevals = {
        {1,2}, {3,5}, {6, 7}, {8, 10}, {12, 16}
    };
    Interval i = {4, 9};
    
    printVector(sln.insert(intevals, i));
}

void TestInsert2()
{
    Solution sln;
    vector<Interval> intevals = {
    };
    Interval i = {4, 9};
    
    printVector(sln.insert(intevals, i));
}

void TestInsert3()
{
    Solution sln;
    vector<Interval> intevals = {
        {1, 5}
    };
    Interval i = {2, 3};
    
    printVector(sln.insert(intevals, i));
}

void TestInsert4()
{
    Solution sln;
    vector<Interval> intevals = {
        {1, 5}
    };
    Interval i = {0, 3};
    
    printVector(sln.insert(intevals, i));
}

int main()
{
    Test0();
    TestInsert1();
    TestInsert2();
    TestInsert3();
    TestInsert4();
    
    return 0;
}
