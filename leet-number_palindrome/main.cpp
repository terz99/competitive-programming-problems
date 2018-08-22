#include <bits/stdc++.h>
using namespace std;

static const auto ios_base_sync_off = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        int y = x, z = 0;
        while(y){
            z = z*10 + y%10;
            y /= 10;
        }

        if(x == z){
            return true;
        }
        return false;
    }
};

int main(){

    int n;
    cin >> n;
    Solution sol;

    return 0;
}