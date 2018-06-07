#include <iostream>
#include <cstring>
using namespace std;

class Solution{

public:
    
    string longestPalindrome(string s){

        int n = (int)s.length();
        int dp[n+5][n+5];
        bool isPal[n+5][n+5];

        memset(dp, 0, sizeof(dp));
        memset(isPal, false, sizeof(isPal));
        for(int i = 0; i < n; i++){
            isPal[i][i] = true;
        }
        int maxI = 0;
        int maxJ = 0;
        int maxx = 1;
        for(int i = 0; i < n-1; i++){
            if(s[i] == s[i+1]){
                isPal[i][i+1] = true;
                dp[i][i+1] = 1;
                maxx = 2;
                maxI = i;
                maxJ = i+1;
            }
        }

        for(int gap = 2; gap < n; gap++){
            for(int i = 0; i < n-gap; i++){

                int j = i + gap;

                if(s[i] == s[j] && isPal[i+1][j-1]){
                    isPal[i][j] = true;
                }

                if(isPal[i][j]){
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1 - dp[i+1][j-1];

                    if(maxx < j-i+1){
                        maxx = j-i+1;
                        maxI = i;
                        maxJ = j;
                    }
                } else {
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
            }
        }

        string res;
        for(int k = maxI; k <= maxJ; k++){
            res += s[k];
        }
        return res;
    }
};

int main(){

    Solution sol;
    string s;
    cin >> s;
    string res = sol.longestPalindrome(s);
    cout << res << endl;
}