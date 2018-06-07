#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        if(p.length() == 0){
            return s.length() == 0;
        }

        if(p.length() == 1 || p[1] != '*'){
            if(s.length() < 1 || (p[0] != '.' && s[0] != p[0])){
                return false;
            }
            return isMatch(s.substr(1), p.substr(1));
        } else {

            int len = static_cast<int>(s.length());

            int i = -1;
            while(i < len && (i < 0 || p[0] == '.' || p[0] == s[i])){
                if(isMatch(s.substr(i+1), p.substr(2))){
                    return true;
                }
                i++;
            }
            return false;
        }
    }
};

int main() {
    return 0;
}