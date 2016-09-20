#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;


class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> row;
        row.resize(numRows + 1);
        
        for (int i = 0; i <= numRows; ++i) {
            row[i] = C(numRows, i);
        }
        return row;
    }
    
private:
    int C(int m, int n) {
        long long ans = 1;
        
        for (int i = 0; i < n; ++i) {
            ans *= (m-i);
            ans /= (i+1);
        }
        return (int)ans;
    }
};


template <typename T>
void printBoard(const vector<T>& board) {
    int n = (int)board.size();
    for (int i = 0; i < n; ++i) {
            cout << board[i];
            if (i < n - 1) cout << " ";
            else cout << endl;
    }
    cout << endl;
}


void Test0()
{
    Solution sln;
    printBoard(sln.getRow(6));
}

int main()
{
    Test0();
    
    return 0;
}
