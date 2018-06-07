#include <bits/stdc++.h>
using namespace std;

int solve(vector< vector<int> >& mat, int& k){

    int n = mat.size();
    int m = mat[0].size();
    vector< vector<int> > sum;
    sum.resize(n);
    for(int i = 0; i < n; i++){
        sum[i].resize(m);
        for(int j = 0; j < m; j++){
            if(mat[i][j] == -1){
                sum[i][j] = 0;
            } else {
                sum[i][j] = mat[i][j] + ((j == 0) ? 0 : sum[i][j-1]);
            }
        }
    }

    int cnt = 0;
    int res = INT_MAX;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(mat[i][j] == -1){
                cnt = k;
            }

            if(cnt > 0){
                cnt--;
            } else if(j >= k-1){
                res = min(res, sum[i][j]-((j-k < 0) ? 0 : sum[i][j-k]));
            }
        }
    }
    return res;
}

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    vector< vector<int> > mat;
    mat.resize(n);
    for(int i = 0; i < n; i++){
        mat[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    cout << solve(mat, k) << endl;

    return 0;
}