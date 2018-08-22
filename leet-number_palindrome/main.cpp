#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int l = 0, r = int(s.length()-1);
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
};

static const auto ios_base_sync_off = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){

    int n;
    cin >> n;
    Solution sol;

    return 0;
}