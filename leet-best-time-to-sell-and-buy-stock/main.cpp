#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        
        if(n == 0 || k == 0){
            return 0;
        }
        
        if(k >= n/2){
            return quickSolve(k, prices);
        }
        
        int dp[k+5][n+5];
        memset(dp, 0, sizeof(dp));

        for(int i = 1; i <= k; i++){

            int maxx = -prices[0];
            for(int j = 1; j < n; j++){
                dp[i][j] = max(dp[i][j-1], prices[j]+maxx);
                maxx = max(maxx, dp[i-1][j-1]-prices[j]);
            }
        }

        return dp[k][n-1];
    }

    private:

    int quickSolve(int k, vector<int>& prices){

        int n = prices.size();
        int res = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] > prices[i-1]){
                res += prices[i]-prices[i-1];
            }
        }
        return res;
    }
};

int main(){

    return 0;
}