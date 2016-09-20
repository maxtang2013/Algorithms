#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct Comp {
    bool operator()(const Point& p0, const Point& p1) {
        if (p0.x < p1.x) return true;
        if (p0.x > p1.x) return false;
        return p0.y < p1.y;
    }
};

typedef long long ll;

template<class T>
T gcd(T m, T n) {
    if (m < n) return gcd(n, m);
    
    if (n == 0) return m;
    
    return gcd(n, m%n);
}

class Solution {
    
public:
    // Other people's solution, originally using double for keys.
    //   1), shorter
    //   2), with O(n) space.
    int maxPoints(vector<Point>& points) {
        
        int n = (int) points.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> pointsOnLine;
            int pointsOnVerticalLine = 0;
            int pointsOnHorizontalLine = 0;
            int x0 = points[i].x, y0 = points[i].y;
            int samePointsNum = 1;
            
            int localMax = 0;
            for (int j = i + 1; j < n; ++j) {
                if (x0 == points[j].x && y0 == points[j].y) {
                    ++samePointsNum;
                } else if (x0 == points[j].x){
                    ++pointsOnVerticalLine;
                } else if (y0 == points[j].y) {
                    ++pointsOnHorizontalLine;
                } else {
                    int A = points[j].y - y0;
                    int B = points[j].x - x0;
                    int g = gcd(abs(A), abs(B));
                    A /= g;
                    B /= g;
                    if (A < 0) {
                        A = -A;
                        B = -B;
                    }
                    ostringstream str;
                    str << A << "," << B;
                    localMax = max(localMax, ++pointsOnLine[str.str()]);
                }
            }
            localMax = max(localMax, pointsOnHorizontalLine);
            localMax = max(localMax, pointsOnVerticalLine);
            localMax += samePointsNum;
            ans = max(localMax, ans);
        }
        return ans;
    }
    
    int maxPoints_old(vector<Point>& points) {
        int n = (int)points.size();
        if (n == 0) return 0;
        
        sort(points.begin(), points.end(), Comp());
        
        unordered_map<string, unordered_set<int>> lines;
        int ans = 1;
        
        int ni, nj;
        string theLine;
        for (int i = 0;  i < n; i = ni) {
            ni = i+1;
            while (ni < n && points[ni].x == points[i].x && points[ni].y == points[i].y) {
                ++ni;
            }
            if (ni == n) {
                ans = max(ans, ni - i);
            }
            
            for (int j = ni; j < n; j = nj) {
                
                nj = j+1;
                while (nj < n && points[nj].x == points[j].x && points[nj].y == points[j].y) {
                    ++nj;
                }
                
                string line = getLine(points[i], points[j]);
                if (lines.count(line) == 0) {
                    lines[line] = {};
                }
                
                unordered_set<int> &ps = lines[line];
                int t = i;
                while (t != ni)
                    ps.insert(t++);
                while (j != nj)
                    ps.insert(j++);
                
                if (ps.size() > ans) {
                    ans = (int)ps.size();
                    theLine = line;
                }
                
            }
        }
        return ans;
    }
    
private:
    
    string getLine(const Point& p0, const Point& p1) {
        ostringstream str;
        if (p0.x == p1.x) {
            str << p0.x;
            return str.str();
        }
        
        //y0 = Ax0 + B;
        //y1 = Ax1 + B;
        //A = (y0-y1) / (x0 - x1);
        //B = y0 - x0 * (y0 - y1) / (x0 - x1) = (x0y1 - x1y0) / (x0 - x1);
        
        // (x0 - x1) * y = (y0-y1) * x + (x0y1 - x1y0);
        
        ll A = p0.x - p1.x;
        ll B = p0.y - p1.y;
        ll C = (p0.x*(ll)p1.y - p1.x*(ll)p0.y);
        ll a = abs(A), b = abs(B), c = abs(C);
        
        ll g = gcd(a, b);
        g = gcd(g, c);
        
        A /= g;
        B /= g;
        C /= g;
        str << A << "y=" << B << "x" << C;
        return str.str();
    }
};


void Test0()
{
    Solution sln;
    
    vector<Point> points = {{1000, 1000}, {2000, 2000}, {10000000,10000000}, {10000000,10000001}, };
    cout << sln.maxPoints(points) << endl;
}

void Test1()
{
    Solution sln;
    vector<Point> points = {{0,0},{1,1},{1,-1}};
    cout << sln.maxPoints(points) << endl;
}

void Test2()
{
    Solution sln;
    vector<Point> points = {{4,0},{4,-1},{4,5}};
    cout << sln.maxPoints(points) << endl;
}

void Test3()
{
    Solution sln;
    
    vector<Point> points = {{40,-23},{9,138},{429,115},{50,-17},{-3,80},{-10,33},{5,-21},{-3,80},{-6,-65},{-18,26},{-6,-65},{5,72},{0,77},{-9,86},{10,-2},{-8,85},{21,130},{18,-6},{-18,26},{-1,-15},{10,-2},{8,69},{-4,63},{0,3},{-4,40},{-7,84},{-8,7},{30,154},{16,-5},{6,90},{18,-6},{5,77},{-4,77},{7,-13},{-1,-45},{16,-5},{-9,86},{-16,11},{-7,84},{1,76},{3,77},{10,67},{1,-37},{-10,-81},{4,-11},{-20,13},{-10,77},{6,-17},{-27,2},{-10,-81},{10,-1},{-9,1},{-8,43},{2,2},{2,-21},{3,82},{8,-1},{10,-1},{-9,1},{-12,42},{16,-5},{-5,-61},{20,-7},{9,-35},{10,6},{12,106},{5,-21},{-5,82},{6,71},{-15,34},{-10,87},{-14,-12},{12,106},{-5,82},{-46,-45},{-4,63},{16,-5},{4,1},{-3,-53},{0,-17},{9,98},{-18,26},{-9,86},{2,77},{-2,-49},{1,76},{-3,-38},{-8,7},{-17,-37},{5,72},{10,-37},{-4,-57},{-3,-53},{3,74},{-3,-11},{-8,7},{1,88},{-12,42},{1,-37},{2,77},{-6,77},{5,72},{-4,-57},{-18,-33},{-12,42},{-9,86},{2,77},{-8,77},{-3,77},{9,-42},{16,41},{-29,-37},{0,-41},{-21,18},{-27,-34},{0,77},{3,74},{-7,-69},{-21,18},{27,146},{-20,13},{21,130},{-6,-65},{14,-4},{0,3},{9,-5},{6,-29},{-2,73},{-1,-15},{1,76},{-4,77},{6,-29}};
    
    sort(points.begin(), points.end(), Comp());
    
//    int len = points.size();
//    int n = 0;
//    for (int i = 0; i < len; ++i) {
//        if (points[i].x + points[i].y == 77)
//        cout << i << " "; //<< " (" << points[i].x << "," << points[i].y << ") ";
//    }
//    cout << endl;
    
    cout << sln.maxPoints(points) << endl;
}

void Test4()
{
    Solution sln;
    
    vector<Point> points = {{0,0},{-1,-1},{2,2}};
    cout << sln.maxPoints(points) << endl;
}

void Test5()
{
    Solution sln;
    
    vector<Point> points = {{2,3},{3,3},{-5,3}};
    cout << sln.maxPoints(points) << endl;
}

void Test6()
{
    
    Solution sln;
    
    vector<Point> points = {{-4,1},{-7,7},{-1,5},{9,-25}};
    cout << sln.maxPoints(points) << endl;
}

int main()
{
//    Test0();
//    Test1();
//    Test2();
//    Test3();
//    Test4();
    Test5();
    Test6();
    return 0;
}
