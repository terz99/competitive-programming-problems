#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;
    int a[n+5];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int res = 1;
    int curr = 1;
    for(int i = 1; i < n; i++){

        if(a[i-1] < a[i]){
            curr++;
        } else {
            res = max(res, curr);
            curr = 1;
        }
    }
    res = max(res, curr);
    cout << res << endl;

    return 0;
}