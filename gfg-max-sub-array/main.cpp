#include <bits/stdc++.h>
using namespace std;

int main(){

    int cases;
    cin >> cases;
    while(cases--){
        
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int res = 0;
        int sum = 0;
        int l, r;
        for(int i = 0; i < n; i++){
            if(a[i] < 0){
                r = i-1;
                
            }
        }
    }

    return 0;
}