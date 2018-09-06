#include <bits/stdc++.h>
using namespace std;

class Solution {

    void generate_parenthesis(vector<string>& res, const string& curr_par, const int& open, const int& closed, const int& n){
        if((int)curr_par.length() == 2*n){
            res.push_back(curr_par);
            return;
        }   
        if(open < n){
            generate_parenthesis(res, curr_par + "(", open+1, closed, n);
        }
        if(closed < open){
            generate_parenthesis(res, curr_par+")", open, closed+1, n);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate_parenthesis(res, "", 0, 0, n);
        return res;
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){

    int n;
    cin >> n;
    Solution sol;

    vector<string> res = sol.generateParenthesis(n);
    for(string s : res){
        cout << s << endl;
    }

    return 0;
}