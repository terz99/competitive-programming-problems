#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, res = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                left++;
            } else {
                right++;
            }
            if(left == right){
                res = max(res, 2*right);
            } else if(right >= left){
                left = right = 0;
            }
        }
        left = right = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == ')'){
                right++;
            } else {
                left++;
            }
            if(left == right){
                res = max(res, 2*left);
            } else if(left >= right){
                left = right = 0;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}