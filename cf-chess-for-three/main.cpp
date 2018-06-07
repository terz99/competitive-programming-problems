#include <bits/stdc++.h>
using namespace std;

const int ALEX = 1;
const int BOB = 2;
const int CARL = 3;

int main(){

    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    int first = ALEX;
    int second = BOB;
    int spectator = CARL;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){

        if(a[i] == first || a[i] == second){
            if(a[i] == first){
                int tmp = second;
                second = spectator;
                spectator = tmp;
            } else {
                int tmp = first;
                first = spectator;
                spectator = tmp;
            }
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}