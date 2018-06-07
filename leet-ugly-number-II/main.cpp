#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        
        int ugly[n+5];
        ugly[0] = 1;
        int i2, i3, i5;
        i2 = i3 = i5 = 0;
        int two = ugly[0]*2;
        int three = ugly[0]*3;
        int five = ugly[0]*5;

        for(int i = 1; i < n; i++){

            ugly[i] = min(two, min(three, five));

            if(ugly[i] == two){
                i2++;
                two = 2*ugly[i2];
            }
            if(ugly[i] == three){
                i3++;
                three = 3*ugly[i3];
            } 
            if(ugly[i] == five){
                i5++;
                five = 5*ugly[i5];
            }
        }
        return ugly[n-1];
    }
};

int main(){

    int n;
    cin >> n;
    Solution sol;
    int res = sol.nthUglyNumber(n);
    cout << res << endl;
    return 0;
}