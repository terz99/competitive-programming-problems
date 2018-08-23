#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

typedef unsigned int ui;

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {

    void populate(unordered_map<char, string>& letters){
        letters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    }

    void solve(ui i, const string& digits, unordered_map<char, string>& letters, vector<string>& res, string curr){
        if(i == digits.length()){
            res.push_back(curr);
            return;
        }
        for(char ch : letters[digits[i]]){
            solve(i+1, digits, letters, res, curr + ch);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        unordered_map<char, string> letters;
        populate(letters);
        vector<string> res;
        solve(0, digits, letters, res, "");
        return res;
    }
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    vector<string> res = sol.letterCombinations(s);
    for(string str : res){
        cout << str << endl;
    }
    return 0;
}