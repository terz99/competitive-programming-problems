#include <bits/stdc++.h>
using namespace std;

class Solution {

    vector<string> getStrings(string& s){

        vector<string> res;
        int i = 0;
        int len = (int)s.length();
        while(i < len){

            while(i < len && s[i] == (char)(32)) i++;

            string tmp;
            while(i < len && s[i] != (char)(32)){
                tmp += s[i];
                i++;
            }
            if((int)tmp.length() != 0){
                res.push_back(tmp);
            }
        }
        return res;
    }

public:
    void reverseWords(string &s) {

        vector<string> v = getStrings(s);
        s = "";
        for(int i = v.size()-1; i >= 0; i--){
            s = s + v[i];
            if(i != 0) s = s + " ";
        }
    }
};

int main(){

    string s;
    getline(cin, s);
    Solution sol;
    sol.reverseWords(s);
    cout << s << endl;

    return 0;
}
