#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define IO ios_base::sync_with_stdio(false)

class Solution {

    string cases = "+-/*";

    int getCase(string c){

        size_t pos = cases.find(c);
        if(pos == string::npos){
            return -1;
        }
        return (int)pos;
    }

public:
    int evalRPN(vector<string>& tokens) {

        stack<int> s;
        for(int i = 0; i < (int)tokens.size(); i++){

            int c = getCase(tokens[i]);
            int a, b, res;
            switch (c) {
                case 0:
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                res = b + a;
                s.push(res);
                break;

                case 1:
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                res = b - a;
                s.push(res);
                break;

                case 2:
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                res = b / a;
                s.push(res);
                break;

                case 3:
                a = s.top(); s.pop();
                b = s.top(); s.pop();
                res = b*a;
                s.push(res);
                break;

                default:
                s.push(stoi(tokens[i], nullptr, 0));
            }
        }

        int res = s.top(); s.pop();
        return res;
    }
};

int main(){

    IO;

    vector<string> v;
    while(true){

        string tmp;
        cin >> tmp;
        if(tmp == "?") break;
        v.push_back(tmp);
    }

    Solution sol;
    int res = sol.evalRPN(v);
    cout << res << endl;

    return 0;
}
