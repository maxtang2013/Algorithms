#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

struct Item {
    int x;
    int y;
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = (int)board.size();
        if (n == 0) return;
        int m = (int)board[0].size();
        if (m == 0) return;
        int i, j;
        vector<Item> stack;
        bool** mask = new bool*[n];
        Item dirs[] = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        
        for (i = 0; i < n; ++i)
        {
            mask[i] = new bool[m];
            memset(mask[i], 0, m);
        }
        
        // Be careful!!!!!  (m != n)
        for (i = 0; i < n; ++i)
        {
            Item item2 = {i, -1}, item3 = {i, m};
            
            stack.push_back(item2);
            stack.push_back(item3);
        }
    
        for (i = 0; i < m; ++i)
        {
            Item item = {-1, i}, item1 = {n, i};
            
            stack.push_back(item);
            stack.push_back(item1);
        }
        
        while (!stack.empty())
        {
            Item item = stack.back();
            stack.pop_back();
            
            for (i = 0; i < sizeof(dirs) / sizeof(Item); ++i)
            {
                int x1 = item.x + dirs[i].x;
                int y1 = item.y + dirs[i].y;
                
                if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m
                    && board[x1][y1] == 'O' && !mask[x1][y1]) // only add unmasked elements to stack!!!!!
                {
                    mask[x1][y1] = 1;
                    Item item1 = { x1, y1 };
                    stack.push_back(item1);
                }
            }
        }
        
        for (i = 0; i < board.size(); ++i)
        {
            const vector<char> &vec = board[i];
            for (j = 0; j < vec.size(); ++j)
            {
                if (!mask[i][j])
                    board[i][j] = 'X';
            }
        }
        
        for (i = 0; i < n; ++i)
        {
            delete []mask[i];
        }
        delete[] mask;
    }
};

void PrintBoard(const vector<vector<char>>& board)
{
    for (int i = 0; i < board.size(); ++i)
    {
        const vector<char> &vec = board[i];
        for (int j = 0; j < vec.size(); ++j)
        {
            printf("%c", vec[j]);
        }
        printf("\n");
    }
}

void Test0()
{
    Solution sln;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    sln.solve(board);
    
    PrintBoard(board);
    printf("\n");
}

void Test1()
{
    Solution sln;
    vector<vector<char>> board = {
        {'O', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'X'}
    };
    sln.solve(board);
    
    PrintBoard(board);
    printf("\n");
}

void Test2()
{
    vector<vector<char>> board = {
        {'X','O','X','O','X','O'},
        {'O','X','O','X','O','X'},
        {'X','O','X','O','X','O'},
        {'O','X','O','X','O','X'}
    };
    Solution sln;
    sln.solve(board);
    
    PrintBoard(board);
    printf("\n");
    
//    [
//     "XOXOXO",
//     "OXXXOX",
//     "XXXOXO",
//     "OXOXOX"]
//    
//    [
//     "XOXOXO",
//     "OXXXXX",
//     "XXXXXO",
//     "OXOXOX"]}
    
    
}

int main()
{
    //Test0();
    //Test1();
    Test2();
    
    return 0;
}
