#include <bits/stdc++.h>
using namespace std;

#define DEBUG 0
#define nullptr NULL

typedef long long int ll;

const int SIZE = (1 << 10); 

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cases;
    cin >> cases;

    vector<ll> dp(SIZE);

    while(cases--){
        int tmp;
        cin >> tmp;
        int bit_mask = 0;
        if(tmp == 0){
            dp[1]++;
            continue;
        }
        while(tmp > 0){
            bit_mask = bit_mask | (1 << (tmp%10));
            tmp /= 10;
        }
        dp[bit_mask]++;
    }

    ll res = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = i+1; j < SIZE; j++){
            if(i & j){
                res += dp[i]*dp[j];
            }
        }
    }

    for(int i = 0; i < SIZE; i++){
        res += (dp[i]*(dp[i]-1))/2ll;
    }

    cout << res << endl;


    return 0;
}