#include <bits/stdc++.h>
using namespace std;

class Solution {

    void removeUtil(string s, set<string>& res, int last_i, int last_j, char ch[]){
        for(int stack = 0, i = last_i; i < s.length(); i++){
            if(s[i] == ch[0]) stack++;
            if(s[i] == ch[1]) stack--;
            if(stack >= 0) continue;
            for(int j = last_j; j <= i; j++){
                if(s[j] == ch[1] && (j == last_j || s[j-1] != ch[1])){
                    removeUtil(s.substr(0, j) + s.substr(j+1), res, i, j, ch);
                }
            }
            return;
        }

        string rev = s;
        reverse(rev.begin(), rev.end());
        if(ch[0] == '('){
            char newch[] = {')', '('};
            removeUtil(rev, res, 0, 0, newch);
        } else {
            res.insert(rev);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> res;
        char ch[] = {'(', ')'};
        removeUtil(s, res, 0, 0, ch);      
        vector<string> ans;
        for(auto el : res){
            ans.push_back(el);
        }
        return ans;
    }
};

int main(){
    return 0;
}