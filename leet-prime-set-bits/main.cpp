#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool primes[25];

    void findPrimes(){
        for(int i = 2; i < 25; i++) primes[i] = true;
        for(int i = 2; i*i < 25; i++){
            if(primes[i]){
                for(int j = 2*i; j < 25; j += i){
                    primes[j] = false;
                }
            }
        }
    }

public:
    int countPrimeSetBits(int L, int R) {
        findPrimes();
        int cnt = 0;
        for(int i = L; i <= R; i++){
            int numOfBits = __builtin_popcount(i);
            if(primes[numOfBits]){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){

    int l, r;
    cin >> l >> r;
    Solution sol;
    cout << sol.countPrimeSetBits(l, r) << endl;

    return 0;
}