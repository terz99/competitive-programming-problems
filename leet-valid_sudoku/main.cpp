#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = 9;

        // check rows
        for(int i = 0; i < n; i++){
            vector<bool> vis(10, false);
            for(int j = 0; j < n; j++){
                if(board[i][j] == '.') continue;
                int idx = (int)board[i][j]-'0';
                if(vis[idx]) return false;
                vis[idx] = true;
            }
        }      

        // check columns
        for(int j = 0; j < n; j++){
            vector<bool> vis(10, false);
            for(int i = 0; i < n; i++){
                if(board[i][j] == '.') continue;
                int idx = (int)board[i][j]-'0';
                if(vis[idx]) return false;
                vis[idx] = true;
            }
        }

        // check 3x3
        for(int I = 0; I < n; I += 3){
            for(int J = 0; J < n; J += 3){
                vector<bool> vis(10, false);
                for(int i = I; i < I+3; i++){
                    for(int j = J; j < J+3; j++){
                        if(board[i][j] == '.') continue;
                        int idx = (int)board[i][j]-'0';
                        if(vis[idx]) return false;
                        vis[idx] = true;
                    }
                }
            }
        }
        return true;
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