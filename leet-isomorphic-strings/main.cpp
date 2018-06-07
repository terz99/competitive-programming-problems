#include <bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false)
#define endl "\n"

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int n = (int)s.length();
        int memo[257];
        bool vis[257];
        memset(memo, -1, sizeof(memo));
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < n; i++){

            if(memo[(int)s[i]] == -1 && !vis[(int)t[i]]){
                memo[(int)s[i]] = (int)t[i];
                s[i] = t[i];
                vis[(int)t[i]] = true;
            } else {
                s[i] = (char)(memo[(int)s[i]]);
            }
        }
        // cout << s << endl << t << endl;
        return (s == t);
    }
};

int main(){

    IO;

    string s, t;
    cin >> s >> t;
    Solution sol;
    cout << sol.isIsomorphic(s, t) << endl;

    return 0;
}
