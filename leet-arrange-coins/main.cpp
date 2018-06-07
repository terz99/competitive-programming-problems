#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {

        double N = (double)n;
        double k1 = (-1.0 + sqrt(1.0 + 4.0*2.0*N))/2.0;
        double k2 = (-1.0 - sqrt(1.0 + 4.0*2.0*N))/2.0;
        return max((int)k1, (int)k2);
    }
};

int main() {

    int n;
    cin >> n;
    Solution sol;
    cout << sol.arrangeCoins(n) << endl;

    return 0;
}