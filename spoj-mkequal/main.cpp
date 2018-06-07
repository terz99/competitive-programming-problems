#include <iostream>
using namespace std;

int main(){

    int cases;
    cin >> cases;
    while(cases--){

        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int tmp;
            cin >> tmp;
            sum += tmp;
        }

        if(sum%n == 0){
            cout << n << endl;
        } else {
            cout << n-1 << endl;
        }
    }

    return 0;
}
