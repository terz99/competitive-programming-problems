#include <bits/stdc++.h>
using namespace std;

const int N = 6;

int get_max_hourglass(int mat[N][N]){
    int dx[] = {-1, -1, -1, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, 0, -1, 0, 1};
    const int d_size = 7;
    int res = INT_MIN;
    for(int i = 1; i < N-1; i++){
        for(int j = 1; j < N-1; j++){
            int curr = 0;
            for(int k = 0; k < d_size; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                curr += mat[x][y]; 
            }
            cout << curr << endl;
            res = max(res, curr);
        }
    }
    return res;
}

int main(){
    int mat[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
    }
    
    // cout << get_max_hourglass(mat) << endl;
}
