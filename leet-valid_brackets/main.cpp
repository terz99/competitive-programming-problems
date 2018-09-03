#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool isValid(const char& a, const char& b){
        return ((a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']'));
    }

public:
    bool isValid(string s) {
        stack<char> myStack;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                myStack.push(c);
            } else {
                if(myStack.empty()) return false;
                if(isValid(myStack.top(), c)){ 
                    myStack.pop();
                } else {
                    return false;
                }
            }
        }
        return myStack.empty();
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){
    return 0;
}