#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector< vector<int> > dp(n, vector<int>(m, INT_MAX));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(i == 0){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                } else if(j == 0){
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[n-1][m-1];     
    }
};

int main(){

    int n, m;
    cin >> n >> m;
    vector< vector<int> > mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    Solution sol;
    cout << sol.minPathSum(mat) << endl;

    return 0;
}