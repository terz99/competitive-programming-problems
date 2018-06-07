#include <bits/stdc++.h>
using namespace std;

int main() {

    int cases;
    cin >> cases;
    while(cases--){

        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int minEndsHere = 1;
        int maxEndsHere = 1;
        int res = 1;

        for(int i = 0; i < n; i++){

            if(a[i] > 0){
                maxEndsHere = maxEndsHere*a[i];
                minEndsHere = min(minEndsHere*a[i], 1);
            } else if(a[i] == 0){
                maxEndsHere = 1;
                minEndsHere = 1;
            } else {
                int tmp = maxEndsHere;
                maxEndsHere = max(minEndsHere*a[i], 1);
                minEndsHere = tmp*a[i];
            }

            if(res < maxEndsHere){
                res = maxEndsHere;
            }
        }
        cout << res << endl;
    }

	return 0;
}