#include <bits/stdc++.h>
using namespace std;

int main() {

    int cases;
    cin >> cases;
    while(cases--){

        int n;
        cin >> n;
        n += 2;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < n; i++){

            if(a[abs(a[i])] > 0){
                a[abs(a[i])] = -a[abs(a[i])];
            } else {
                cout << abs(a[i]) << " ";
            }
        }
        cout << endl;
    }

    return 0;
}