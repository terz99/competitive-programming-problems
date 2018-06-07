#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        int i = 0;
        int j = 0;
        int sidx = -1;
        int idx = -1;
        while(i < s.length()){

            if(j < p.length() && (p[j] == '?' || p[j] == s[i])){
                i++;
                j++;
            } else if(j < p.length() && p[j] == '*'){
                sidx = j;
                idx = i;
                j++;
            } else if(sidx != -1){
                j = sidx + 1;
                i = idx + 1;
                idx++;
            } else return false;
        }

        while(j < p.length() && p[j] == '*'){
            j++;
        }

        return j == p.length();
    }
};

int main() {
    return 0;
}