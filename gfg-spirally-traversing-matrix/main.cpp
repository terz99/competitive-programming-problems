#include <bits/stdc++.h>
using namespace std;

bool outOfBounds(int x, int y, int n, int m){
    return (x < 0 || x >= n || y < 0 || y >= m);
}

int main() {

    int cases;
    cin >> cases;
    while(cases--){

        int n = 4;
        int mat[n+5][n+5];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }

        int i, j;
        i = j = 0;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int currDir = 0;
        int cnt = 0;
        while(cnt < n*n){

            cnt++;
            cout << mat[i][j] << " ";
            mat[i][j] = -1;
            int ni = i + dx[currDir];
            int nj = j + dy[currDir];
            if(outOfBounds(ni, nj, n, n) || mat[ni][nj] == -1){
                currDir = (currDir+1)%4;
                ni = i + dx[currDir];
                nj = j + dy[currDir];
            }
            i = ni;
            j = nj;
        }
        cout << endl;
    }

    return 0;
}