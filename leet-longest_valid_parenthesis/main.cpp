#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.length();
        vector<int> dp(n+1);
        for(int i = 0; i < n; i++){
            if(i > 0 && s[i] == ')'){
                if(s[i-1] == '('){
                    dp[i+1] = dp[i-1] + 2;
                } else {
                    if(s[i - dp[i] - 1] == '(')
                        dp[i+1] = dp[i] + dp[i - dp[i] - 1] + 2;
                }
                res = max(res, dp[i+1]);
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
    return 0;
}