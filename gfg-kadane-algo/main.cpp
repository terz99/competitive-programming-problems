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

        int maxEndsHere = 0;
        int maxSoFar = -(1 << 30);
        for(int i = 0; i < n; i++){

            maxEndsHere += a[i];
            if(maxSoFar < maxEndsHere){
                maxSoFar = maxEndsHere;
            }
            if(maxEndsHere < 0){
                maxEndsHere = 0;
            }
        }
        cout << maxSoFar << endl;
    }

	return 0;
}