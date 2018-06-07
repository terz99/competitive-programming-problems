#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int subsequenceCountUtil(const string& s, const string& t, int n, int m){

    int& ret = dp[n][m];
    if(ret == -1){

        if(m == 0){
            ret = 1;
        } else if(n == 0){
            ret = 0;
        } else if(s[n] != t[m]){
            ret = subsequenceCountUtil(s, t, n-1, m);
        } else {
            ret = subsequenceCountUtil(s, t, n-1, m) + subsequenceCountUtil(s, t, n-1, m-1);
        }
    }
    return ret;
}
int subsequenceCount(string S, string T){
    memset(dp, -1, sizeof(dp));
    return subsequenceCountUtil("."+S, "."+T, S.length(), T.length());
}
 


int main(){

    string a, b;
    cin >> a >> b;
    cout << subsequenceCount(a, b) << endl;

    return 0;
}