#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool solve(vector< vector<char> >& board, int index, vector< vector<bool> >& row, vector< vector<bool> >& col, vector< vector< vector<bool> > >& square){
        if(index > 80) return true;
        int i = index/9, j = index%9;
        if(board[i][j] != '.'){
            return solve(board, index+1, row, col, square);
        }
        for(int val = 1; val <= 9; val++){
            if(row[i][val] || col[j][val] || square[i/3][j/3][val]) continue;
            row[i][val] = true;
            col[j][val] = true;
            square[i/3][j/3][val] = true;
            board[i][j] = (char)val + '0';
            if(solve(board, index+1, row, col, square)) return true;
            row[i][val] = false;
            col[j][val] = false;
            square[i/3][j/3][val] = false;
            board[i][j] = '.';
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        vector< vector<bool> > row(9, vector<bool>(10, false));
        vector< vector<bool> > col(9, vector<bool>(10, false));
        vector< vector< vector<bool> > > square(3, vector< vector<bool> >(3, vector<bool>(10, false)));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                int val = (int)board[i][j] - '0';
                row[i][val] = true;
                col[j][val] = true;
                square[i/3][j/3][val] = true;
            }
        }
        solve(board, 0, row, col, square);
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){
    return 0;
}