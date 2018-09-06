#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_negative = (dividend < 0) ^ (divisor < 0);
        long ldividend = abs((long)dividend);
        long ldivisor = abs((long)divisor);
        long res = 0;

        while(ldividend >= ldivisor){
            long factor = 1;
            long divisor_multi = ldivisor;
            while(divisor_multi + divisor_multi < ldividend && divisor_multi + divisor_multi > 0){
                divisor_multi = divisor_multi + divisor_multi;
                factor = (factor << 1);
            }
            res += factor;
            ldividend -= divisor_multi;
        }

        if(is_negative){
            res = -res;
        } else {
            if(res == 2147483648ll){
                res = 2147483647;
            }
        }
        return res;
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){
    int a, b;
    cin >> a >> b;
    Solution sol;
    cout << sol.divide(a, b) << endl;
    return 0;
}