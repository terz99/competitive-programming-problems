#include <bits/stdc++.h>
using namespace std;

class Solution {

    vector<double> sum;
    vector< vector<double> > dp;
    int n, k;

    double avg(int i, int j){
        return ((i == 0) ? sum[j] : sum[j] - sum[i-1])/(double)(j-i+1);
    }

    double solve(int i, int j){
        double& ret = dp[i][j];
        if(ret == -1){
            if(i == n){
                ret = 0;
            } else if(j == k-1){
                ret = avg(i, n-1);
            } else {
                double tmp = 0;
                for(int idx = i; idx < n; idx++){
                    tmp = max(tmp, avg(i, idx) + solve(idx+1, j+1));
                }
                ret = tmp;
            }
        }
        return ret;
    }

public:
    double largestSumOfAverages(vector<int>& A, int K) {
        n = A.size();
        k = K;
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return (double)A[0];
        }
        sum.resize(n+2);
        dp.resize(n+2, vector<double>(n+2, -1));
        sum[0] = (double)A[0];
        for(int i = 1; i < n; i++){
            sum[i] = sum[i-1] + (double)A[i];
        }
        return solve(0, 0);
    }
};

int main(){



    return 0;
}