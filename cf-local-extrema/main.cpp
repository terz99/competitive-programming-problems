#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int res = 0;
    for(int i = 1; i < n-1; i++){
        if(a[i-1] > a[i] && a[i+1] > a[i]){
            res++;
        } else if(a[i-1] < a[i] && a[i+1] < a[i]){
            res++;
        }
    }
    cout << res << endl;

    return 0;
}