#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(haystack == needle) return 0;

        for(int i = 0; i < (int)haystack.length(); i++){
            int j;
            for(j = 0; j < (int)needle.length(); j++){
                if(needle[j] != haystack[i+j]){
                    break;
                }
            }
            if(j == (int)needle.length()) return i;
        }
        return -1;
    }
};

int main(){

    Solution sol;
    string a, b;
    cin >> a >> b;
    cout << sol.strStr(a, b) << endl;

    return 0;
}