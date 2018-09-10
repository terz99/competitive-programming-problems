#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool continuos = true;

    void dfs(string s, vector<string> words, int head, int start, int len, set<int> res){
        if(words.size() == 0){
            res.insert(head);
            return;
        }
        int size = s.length() - words.size()*len;
        for(int i = start; i <= size && continuos; i += len){
            string temp = s.substr(i, len);
            if(find(words.begin(), words.end(), temp)){
                erase(words.begin(), words.end(), temp);
                dfs(s, words, head, i+len, len, res);
                words.push_back(temp);
            } else {
                continuos = false;
                return;
            }
        }
    }

public:
    vector<int> findSubstring(string s, vector<string>& words) {
       set<int> res;
       if(words.size() == 0 || s.length() == 0){
           return vector<int>();
       } 

       int len = words[0].length();
       vector<string> sstr;
       for(string str : words){
           sstr.push_back(str);
       }
       for(int i = 0; i <= s.length()-words.size()*len; i++){
           continuos = true;
           dfs(s, sstr, i, i, len, res);
       }
    }
};

int main(){
    return 0;
}