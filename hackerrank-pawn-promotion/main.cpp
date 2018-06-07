#include <bits/stdc++.h>

using namespace std;

#define KNIGHT 0
#define ROOK 1
#define BISHOP 2
#define QUEEN 3

int knight[2][8] = {
    {-2, -1, 1, 2, 2, 1, -1, -2}, 
    {1, 2, 2, 1, -1, -2, -2, -1}
};

inline bool out_of_bounds(const int& x, const int& y){
    return (x < 0 || x >= 8 || y < 0 || y >= 8);
}

int check(const int& x, const int& y, const int& flag, const vector< vector<char> >& board){

    if(flag == KNIGHT){

        for(int i = 0; i < 8; i++){
            int nx = x+knight[0][i];
            int ny = y+knight[1][i];
            if(!out_of_bounds(nx, ny) && board[nx][ny] == 'k') return 1;
        }
    } else if(flag == ROOK){

        for(int i = 1; i <= 7; i++){
            if(board[x+i][y] == 'k'){
                return 1;
            } else if(board[x+i][y] != '#'){
                break;
            }
        }
        for(int i = 1; i <= 7; i++){
            if(out_of_bounds(x, y+i)) continue;
            if(board[x][y+i] == 'k'){
                return 1;
            } else if(board[x][i+y] != '#'){
                break;
            }
        }
        for(int i = 1; i <= 7; i++){
            if(out_of_bounds(x, y-i)) continue;
            if(board[x][y-i] == 'k'){
                return 1;
            } else if(board[x][y-i] != '#'){
                break;
            }
        }
    } else if(flag == BISHOP){

        for(int i = 1; i <= 7; i++){
            if(out_of_bounds(x+i, y+i)) continue;
            if(board[x+i][y+i] == 'k'){
                return 1;
            } else if(board[x+i][y+i] != '#'){
                break;
            }
        }
        for(int i = 1; i <= 7; i++){
            if(out_of_bounds(x+i, y-i)) continue;
            if(board[x+i][y-i] == 'k'){
                return 1;
            } else if(board[x+i][y-i] != '#'){
                break;
            }
        }
    } else {
        int one = check(x, y, ROOK, board);
        int two = check(x, y, BISHOP, board);
        if(one == 1 || two == 1){
            return 1;
        }
    }
    return 0;
}

int waysToGiveACheck(vector < vector<char> > board) {

    queue< pair<int, int> > q;
    for(unsigned int i = 0; i < board[0].size(); i++){
        if(board[0][i] == '#' && board[1][i] == 'P'){
            q.push({1, i});
            board[1][i] = '#';
        }
    }

    int ret = 0;
    while(!q.empty()){

        pair<int, int> curr = q.front();
        q.pop();
        ret += check(0, curr.second, KNIGHT, board);
        ret += check(0, curr.second, ROOK, board);
        ret += check(0, curr.second, BISHOP, board);
        ret += check(0, curr.second, QUEEN, board);
    }
    return ret;
}

char choices[] = {'P', 'Q', 'N', 'B', 'R', 'p', 'q', 'n', 'b', 'r'};

int main() {

    srand(time(NULL));

    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        vector< vector<char> > board(8,vector<char>(8));
        for(int board_i = 0;board_i < 8;board_i++){
           for(int board_j = 0;board_j < 8;board_j++){
            //    if(board_i == 0) board[board_i][board_j] = '#';
            //    else if(board_i == 1) board[board_i][board_j] = ((rand()%2) ? 'P' : '#');
            //    else{
            //        int op = rand()%22;
            //        if(op <= 9) board[board_i][board_j] = choices[op];
            //         else board[board_i][board_j] = '#';
            //    }
              cin >> board[board_i][board_j];
           }
        }
        // int x = rand()%6 + 2;
        // int y = rand()%8;
        // board[x][y] = 'k';
        // for(int i = 0; i < 8; i++){
        //     for(int j = 0; j < 8; j++){
        //         cout << board[i][j];
        //     }
        //     cout << endl;
        // }
        int result = waysToGiveACheck(board);
        cout << result << endl;
    }
    return 0;
}
