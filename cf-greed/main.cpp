#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    long long sum = 0;
    long long maxx1 = 0;
    long long maxx2 = 0;
    for(int i = 0; i < n; i++){
        long long tmp;
        cin >> tmp;
        sum += tmp;
    }
    for(int i = 0; i < n; i++){
        long long tmp;
        cin >> tmp;
        if(tmp > maxx1){
            maxx2 = maxx1;
            maxx1 = tmp;
        } else if(tmp > maxx2){
            maxx2 = tmp;
        }
    }

    if(sum <= maxx1+maxx2){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}