#include <bits/stdc++.h>
using namespace std;

class Solution {

    void computeLPS(const string& pat, int lps[]){

        int n = pat.length();
        lps[0] = 0;
        int len = 0;
        int i = 1;

        while(i < n){

            if(pat[len] == pat[i]){

                len++;
                lps[i] = len;
                i++;
            } else {

                if(len != 0){
                    len = lps[len-1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    string shortestPalindrome(string s) {
        
        string org = s;
        string rs = s;
        reverse(rs.begin(), rs.end());
        s = s + "#" + rs;
        int n = s.length();
        int lps[n+5];
        computeLPS(s, lps);

        string tmp = org.substr(lps[n-1]);
        reverse(tmp.begin(), tmp.end());
        return tmp + org;
    }
};

int main(){

    string s;
    cin >> s;
    Solution sol;
    cout << sol.shortestPalindrome(s) << endl;

    return 0;
}