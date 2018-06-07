#include <bits/stdc++.h>
using namespace std;

class location{
    public: 
    int x, y;
    location(int x, int y){
        this->x = x;
        this->y = y;
    }
};

bool vis[105][105];
int n, m;
char board[105][105];
int mat[105][105];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void dfs(int index, int x, int y){

    vis[x][y] = true;
    mat[x][y] = index;
    for(int i = 0; i < 4; i++){

        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) continue;
        if(vis[next_x][next_y] == true) continue;
        if(board[next_x][next_y] == 'X') continue;

        dfs(index, next_x, next_y);
    }
}

int main(){

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }

    int index = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(vis[i][j] == false && board[i][j] != 'X'){
                dfs(index, i, j);
                index++;
            }
        }
    }

    int num_of_rooms = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            num_of_rooms = max(num_of_rooms, mat[i][j]);
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    cout << num_of_rooms << endl;

    return 0;
}