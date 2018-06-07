#include <bits/stdc++.h>
using namespace std;

class Solution {

    int res = 0;

public:
    int integerReplacement(int n) {

        if(n == 1){
            return res;
        }
        if(n == 3){
            res += 2;
            return res;
        }
        if(n == INT_MAX){
            res = 32;
            return res;
        }

        res++;
        if(n & 1){

            if((n+1)%4 == 0){
                integerReplacement(n+1);
            } else {
                integerReplacement(n-1);
            }
        } else {
            integerReplacement(n/2);
        }
        return res;
    }
};

int main(){
        
    Solution sol;
    int k;
    cin >> k;
    cout << sol.integerReplacement(k) << endl;

    return 0;
}