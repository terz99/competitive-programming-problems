#include <bits/stdc++.h>
using namespace std;

class Solution {

    const static int INF = (1 << 30);
    vector< vector<int> > dp;
    string S;

    int solve(int i, int j){
        int& ret = dp[i][j];
        if(ret == -1){
            if(i > j){
                ret = 0;
            } else {
                int tmp = solve(i+1, j) + 1;
                for(int k = i+1; k <= j; k++){
                    if(S[i] == S[k]){
                        tmp = min(tmp, solve(k+1, j) + solve(i, k-1));
                    }
                }
                ret = tmp;
            }
        }
        return ret;
    }

public:
    int strangePrinter(string s) {
        int n = s.length();
        dp.resize(n, vector<int>(n, -1));
        S = s;
        return solve(0, n-1);
    }
};