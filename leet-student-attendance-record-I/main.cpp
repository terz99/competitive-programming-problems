#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'A') cnt++;
        }

        if(cnt > 1){
            return false;
        }

        for(int i = 2; i < s.length(); i++){
            if(s[i-2] == s[i-1] && s[i-1] == s[i] && s[i] == 'L'){
                return false;
            }
        }
        return true;
    }
};

int main(){
    return 0;
}