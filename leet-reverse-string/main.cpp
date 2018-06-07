#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {

        string res;
        string tmp;
        for(int i = 0; i < s.length(); i++){
            if((i/k)%2){
                if(!tmp.empty()){
                    res = res + tmp;
                    tmp = "";
                }
                res = res + s[i];
            } else {
                tmp = s[i] + tmp;
            }
        }      
        if(!tmp.empty()){
            res = res + tmp;
        }
        return res;
    }
};

int main(){

    string s;
    int k;

    // cin >> s >> k;

    srand(time(NULL));
    int n = rand()%10 + 5;
    for(int i = 0; i < n; i++){
        char c = rand()%26;
        s = s + (char)(c+'a');
    }

    k = rand()%5+1;

    cout << s << endl << k << endl;
    Solution sol;
    cout << sol.reverseStr(s, k) << endl;

    return 0;
}