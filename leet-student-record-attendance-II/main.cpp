#include <bits/stdc++.h>
using namespace std;

class Solution {

    int dp[100005][2][3];
    int MOD = 1000000007;

    int checkRecord(int n, int a, int l){

        // cout << n << endl << a << endl << l << endl;
        int& ret = dp[n][a][l];
        if(ret == -1){

            if(n == 0){
                ret = 1;
            } else {

                ret = 0;
                if(a < 1){
                    ret += checkRecord(n-1, a+1, 0);
                    ret %= MOD;
                }
                if(l < 2){
                    ret += checkRecord(n-1, a, l+1);
                    ret %= MOD;
                }
                ret += checkRecord(n-1, a, 0);
                ret %= MOD;
            }
        }
        return ret;
    }

public:
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return checkRecord(n, 0, 0);
    }
};

int main(){

    srand(time(NULL));

    int n;
    cin >> n;
    // n = rand()%100000 + 1;
    // cout << n << endl;
    Solution sol;
    cout << sol.checkRecord(n) << endl;

    return 0;
}