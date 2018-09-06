#include <bits/stdc++.h>
using namespace std;

class Solution {

    int N;
    stack<char> s;

    void generate_parenthesis(const int& curr_num, const string& curr_par, vector<string>& res){
        if(curr_num == 2*N){
            if(s.empty()){
                res.push_back(curr_par);
            } else {
                return;
            }
        } else {
            // put a '('
            s.push('(');
            generate_parenthesis(curr_num+1, curr_par + "(", res);
            s.pop();

            // put a ')'
            if(!s.empty() && s.top() == '('){
                s.pop();
                generate_parenthesis(curr_num+1, curr_par + ")", res);
                s.push('(');
            } else {
                s.push(')');
                generate_parenthesis(curr_num+1, curr_par + ")", res);
                s.pop();
            }
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0){
            return res;
        }
        N = n;
        generate_parenthesis(0, "", res);
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