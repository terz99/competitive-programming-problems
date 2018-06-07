#include <iostream>
#include <cstring>
using namespace std;

class Solution {

private:

    int dp[1005][1005];

    int solve(int i, int j, string &s){
        
        int &ret = dp[i][j];
        if(ret == -1){

            if(i == j){
                ret = 1;
            } else if(s[i] == s[j] && i+1 == j){
                ret = 2;
            } else if(s[i] == s[j]){
                ret = solve(i+1, j-1, s) + 2;
            } else {
                ret = max(solve(i+1, j, s), solve(i, j-1, s));
            }
        }
        return ret;
    }

public:
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        memset(dp, -1, sizeof(dp));
        return solve(0, n-1, s);
    }
};

int main(){
    Solution sol;
    string s;
    cin >> s;
    cout << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}