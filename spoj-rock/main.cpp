#include <iostream>
#include <cstring>
using namespace std;

int dp[205][205];
int best[205][205];

int solve(int s, int e){

    if(s > e) return 0;
    int &ret = dp[s][e];
    if(ret == -1){

        ret = 0;
        for(int i = s; i <= e; i++){
            int curr = best[s][i] + solve(i+1, e);
            ret = max(ret, curr);
        }
    }
    return ret;
}

int main(){

    int cases;
    cin >> cases;
    while(cases--){

        int n;
        cin >> n;
        string s;
        cin >> s;

        memset(best, 0, sizeof(best));
        for(int i = 0; i < n; i++){

            for(int j = i; j < n; j++){

                int diff = 0;
                for(int k = j; k >= i; k--){

                    if(s[k] == '1')
                        diff++;
                    else
                        diff--;

                    if(diff > 0)
                        best[i][j] = j-k+1;
                }
            }
        }

        memset(dp, -1, sizeof(dp));
        cout << solve(0, n-1) << endl;
    }

    return 0;
}
