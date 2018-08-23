#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef unsigned int ui;

static const auto _____ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {

    void populate(unordered_map<string, int>& roms){
        roms = {
            {"M", 1000},
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL", 40},
            {"X", 10},
            {"IX", 9},
            {"V", 5},
            {"IV", 4},
            {"I", 1}
        };
    }

public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<string, int> roms;
        populate(roms);
        for(ui i = 0; i < s.length(); i++){
            string curr;
            if(i+1 < s.length()){
                curr = s[i]; curr += s[i+1];
                if(roms.find(curr) != roms.end()){
                    res += roms[curr];
                    i++;
                    continue;
                }
            }
            curr = s[i];
            res += roms[curr];
        }
        return res;
    }
};

int main(){

    string str;
    cin >> str;
    Solution sol;
    cout << sol.romanToInt(str) << endl;

    return 0;
}