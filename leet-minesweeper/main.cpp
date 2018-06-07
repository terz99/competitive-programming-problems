#include <bits/stdc++.h>
using namespace std;

class Solution {

private:

    vector<int> dx, dy;
    int N, M;

    bool outOfBounds(int x, int y){
        return (x < 0 || x >= N || y < 0 || y >= M);
    }

    void reveal(vector< vector<char> >& board, int x, int y){

        if(board[x][y] == 'E'){

            int cnt = 0;
            for(int i = 0; i < 8; i++){

                int nx = dx[i] + x;
                int ny = dy[i] + y;
                if(!outOfBounds(nx, ny) && board[nx][ny] == 'M'){
                    cnt++;
                }
            }

            if(cnt > 0){
                board[x][y] = (char)('0'+cnt);
            } else {

                board[x][y] = 'B';
                for(int i = 0; i < 8; i++){

                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                    if(!outOfBounds(nx, ny)){
                        reveal(board, nx, ny);
                    }
                }
            }
        }
    }

public:
    vector< vector<char> > updateBoard(vector< vector<char> >& board, vector<int>& click) {
        
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M'){
            board[x][y] = 'X';
            return board;
        }

        dx = {0, 0, 1, -1, 1, 1, -1, -1};
        dy = {1, -1, 0, 0, 1, -1, 1, -1};
        N = board.size();
        M = board[0].size();
        reveal(board, x, y);
        return board;
    }
};

int main(){



    return 0;
}