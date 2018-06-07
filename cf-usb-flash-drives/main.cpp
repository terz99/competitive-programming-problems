#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;
    int m;
    cin >> m;
    int a[n+5];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);
    reverse(a, a+n);

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        if(sum >= m){
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}