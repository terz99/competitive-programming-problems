#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector< vector<char> >& matrix) {

        int n = matrix.size();
        if(n == 0){
            return 0;
        }
        int m = matrix[0].size();
        if(m == 0){
            return 0;
        }

        vector< vector<int> > mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mat[i][j] = (matrix[i][j] == '1');
            }
        }

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
        return res*res;
    }
};

int main() {

    int n, m;
    cin >> n >> m;
    vector< vector<char> > mat(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    Solution sol;
    cout << sol.maximalSquare(mat) << endl;

    return 0;
}