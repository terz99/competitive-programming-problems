#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    sort(a.begin(), a.end());

    int i, j;
    i = 0;
    j = 1;
    int max_points = 0;
    while(i < n && j < n){
        if(a[j] - a[i] <= d){
            max_points = max(max_points, j-i+1);
            j++;
        } else {
            i++;
        }
    }

    cout << n - max_points << endl;

    return 0;
}