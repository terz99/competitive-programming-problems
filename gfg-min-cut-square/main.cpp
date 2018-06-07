#include <iostream>
#include <cmath>
#include <cstring>

const int INF = (1 << 30);
int dp[105][105];

int solve(int a, int b){

    int m = std::min(a, b);
    
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= a; i++){
        dp[i][0] = 0;
        dp[i][1] = i;
    }
    for(int i = 0; i <= b; i++){
        dp[0][i] = 0;
        dp[1][i] = i;
    }
    for(int i = 1; i <= m; i++){
        dp[i][i] = 1;
    }

    for(int i = 2; i <= a; i++){
        for(int j = 2; j <= b; j++){
            
            if(dp[i][j]) continue;

            int curr = INF;
            for(int k = 1; k < i; k++){
                curr = std::min(curr, dp[i-k][j]+dp[k][j]);
            }
            for(int k = 1; k < j; k++){
                curr = std::min(curr, dp[i][j-k]+dp[i][k]);
            }
            dp[i][j] = curr;
        }
    }

    return dp[a][b];
}

int main(){

    int cases;
    std::cin >> cases;
    while(cases--){

        int a, b;
        std::cin >> a >> b;
        std::cout << solve(a, b) << std::endl;
    }

    return 0;
}