#include <bits/stdc++.h>
using namespace std;

void printDuplicates(int arr[], int n) {

    bool ok = true;
    for(int i = 0; i < n; i++){

        int idx = arr[i]%n;
        if(arr[idx]/n == 1){
            ok = false;
            cout << idx << " ";
        }
        arr[idx] += n;
    }
    if(ok){
        cout << -1;
    }
}

int main() {

    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    printDuplicates(a, n);

    return 0;
}