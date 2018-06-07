#include <iostream>
using namespace std;

typedef long long ll;

int main(){

    int cases;
    cin >> cases;
    while(cases--){

        ll n;
        cin >> n;
        ll sum = n*(n+1ll)/2ll;
        for(ll i = 0; (1ll << i) <= n; i++){
            sum -= 2ll*(1ll << i);
        }
        cout << sum << endl;
    }

    return 0;
}