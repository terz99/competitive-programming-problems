#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

class Solution {

    int getPrevTop(stack<int>& s){

        int tmp = s.top();
        s.pop();
        int res = s.top();
        s.push(tmp);
        return res;
    }

public:
    int calPoints(vector<string>& ops) {

        int res = 0;
        stack<int> prev;
        for(ui i = 0; i < ops.size(); i++){

            if(ops[i] == "+"){

                int one = getPrevTop(prev);
                int two = prev.top();
                res += one + two;
                prev.push(one + two);
            } else if(ops[i] == "D"){

                int tmp = prev.top();
                res += 2*tmp;
                prev.push(2*tmp);
            } else if(ops[i] == "C"){

                res -= prev.top();
                prev.pop();
            } else {

                int tmp = stoi(ops[i]);
                res += tmp;
                prev.push(tmp);
            }
        }      
        return res;
    }
};

int main(){

    int n;
    cin >> n;
    vector<string> queries(n);
    for(int i = 0; i < n; i++){
        cin >> queries[i];
    }

    Solution sol;
    cout << sol.calPoints(queries) << endl;

    return 0;
}