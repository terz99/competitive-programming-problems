#include <bits/stdc++.h>
using namespace std;

int solve(vector< vector<int> >& mat){

    int n = mat.size();
    int m = mat[0].size();
    vector< vector<int> > sum(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        sum[i][0] = mat[i][0];
    }
    for(int j = 0; j < m; j++){
        sum[0][j] = mat[0][j];
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){

            if(mat[i][j]){
                sum[i][j] = min(sum[i-1][j-1], min(sum[i-1][j], sum[i][j-1])) + 1;
            } else {
                sum[i][j] = 0;
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res = max(res, sum[i][j]);
        }
    }

    return res;
}

int main(){

    int cases;
    cin >> cases;
    while(cases--){

        int n, m;
        cin >> n >> m;
        vector< vector<int> > mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mat[i][j];
            }
        }

        cout << solve(mat) << endl;
    }

    return 0;
}