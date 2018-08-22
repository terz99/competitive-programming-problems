#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == -pow(2, 31)){
            return 0;
        }
        long res = 0;
        bool neg = false;
        if(x < 0){
            neg = true;
            x *= -1;
        }
        while(x != 0){
            res = res*10 + (x%10);
            if(res > pow(2, 31)){
                return 0;
            }
            x /= 10;
        }
        if(neg){
            res *= -1;
        }      
        return int(res);
    }
};
static const auto io_sync_off = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

int main(){
    int n;
    cin >> n;
    Solution sol;
    cout << sol.reverse(n) << endl;
}