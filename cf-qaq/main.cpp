#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;
    int n = s.length();
    int sum[n+5];
    for(int i = 0; i < n; i++){
        sum[i] = ((i == 0) ? 0 : sum[i-1]) + (s[i] == 'Q');
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'A'){
            int l = sum[i];
            int r = sum[n-1]-sum[i];
            res += l*r;
        }
    }

    cout << res << endl;

    return 0;
}