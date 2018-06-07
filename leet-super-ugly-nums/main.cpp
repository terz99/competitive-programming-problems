#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<int> idx;
        vector<int> p;
        p = primes;
        idx.resize((int)primes.size(), 0);
        int ugly[n+5];
        ugly[0] = 1;

        for(int i = 1; i < n; i++){

            int minn = (1 << 30);
            int minnIdx = -1;
            for(int j = 0; j < (int)primes.size(); j++){
                if(primes[j] < minn){
                    minn = primes[j];
                    minnIdx = j;
                }
            }

            ugly[i] = minn;

            for(int j = 0; j < (int)primes.size(); j++){

                if(ugly[i] == primes[j]){
                    idx[j]++;
                    primes[j] = p[j]*ugly[idx[j]];
                }
            }
        }

        return ugly[n-1];       
    }
};
