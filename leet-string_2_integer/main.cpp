#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

static inline void trim(string &s);

class Solution {

    int toInt(const char& ch){
        return ch-'0';
    }

public:
    int myAtoi(string str) {
        bool isNeg = false;
        bool start = false;
        long res = 0;
        for(int i = 0; i < str.length(); i++){
            
            if(str[i] >= '0' && str[i] <= '9'){
                start = true;
                res = res*10 + toInt(str[i]);
                if(res > INT_MAX){
                    return isNeg ? INT_MIN : INT_MAX;
                }
            } else {

                if(start) break;
                if(str[i] == ' ') continue;
                if(str[i] == '-'){
                    isNeg = true;
                    start = true;
                } else if(str[i] == '+'){
                    start = true;
                } else {
                    break;
                }
            }
        }
        return isNeg ? -res : res;
    }
};

static const auto ios_sync_off = [] () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
};

int main(){

    string str;
    getline(cin, str);
    Solution sol;
    sol.myAtoi(str);

    return 0;
}