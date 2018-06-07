#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, t;
    cin >> n >> t;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int secPerDay = 86400;
    int i; 
    for(i = 0; i < n; i++){
        t -= secPerDay-a[i];
        if(t <= 0){
            break;
        }
    }
    cout << i+1 << endl;

    return 0;
}