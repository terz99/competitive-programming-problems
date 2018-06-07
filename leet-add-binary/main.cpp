#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        
        if(b.length() < a.length()){
            return addBinary(b, a);
        }

        while(a.length() < b.length()) a = "0" + a;

        string res;
        bool carry = false;
        for(int i = a.length()-1; i >= 0; i--){

            if(a[i] == '1' && b[i] == '1'){
                if(carry){
                    res = "1" + res;
                } else {
                    res = "0" + res;
                }
                carry = true;
            } else if(a[i] == '0' && b[i] == '0'){
                if(carry){
                    res = "1" + res;
                } else {
                    res = "0" + res;
                }
                carry = false;
            } else {
                if(carry){
                    res = "0" + res;
                    carry = true;
                } else {
                    res = "1" + res;
                    carry = false;
                }
            }
        }

        if(carry){
            res = "1" + res;
        }
        return res;
    }
};

int main(){

    string a, b;
    cin >> a >> b;
    Solution sol;
    cout << sol.addBinary(a, b) << endl;

    return 0;
}