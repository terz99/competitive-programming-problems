#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int calculateMinimumHP(vector< vector<int> >& dungeon) {
        
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector< vector<int> > dp(n+1, vector<int>(m+1, INT_MAX));
        dp[n][m-1] = 1;
        dp[n-1][m] = 1;
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){

                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = (need <= 0) ? 1 : need;
            }
        }
        return dp[0][0];
    }
};

int main(){

    int n, m;
    cin >> n >> m;
    vector< vector<int> > mat;
    mat.resize(n);
    for(int i = 0; i < n; i++){
        
        mat[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    Solution sol;
    cout << sol.calculateMinimumHP(mat) << endl;

    return 0;
}