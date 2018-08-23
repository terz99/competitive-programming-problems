#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

static const auto _____ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {

    void populate(unordered_map<int, string>& roms){
        roms = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
    }

public:
    string intToRoman(int num) {
        string str = "";
        int left = num;
        vector<int> roms_list = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        unordered_map<int, string> roms;
        populate(roms);
        while(left){
            for(int k : roms_list){
                if(left >= k){
                    str += roms[k];
                    left -= k;
                    break;
                }
            }
        }
        return str;
    }
};

int main(){

    int n;
    cin >> n;
    Solution sol;
    cout << sol.intToRoman(n) << endl;

    return 0;
}