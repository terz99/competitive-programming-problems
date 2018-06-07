#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> v;
        int i = 0;
        int cnt = 0;
        for(int j = 0; i < s.length(); j++){
            if(s[j] == '1') cnt++;
            else cnt--;
            if(cnt == 0){
                v.push_back("1" + makeLargestSpecial(s.substr(i+1, j-i-1)) + "0");
                i = j + 1;
            }
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        string ret = "";
        for(auto el : v){
            ret += el;
        }
        return ret;
    }
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    cout << sol.makeLargestSpecial(s) << endl;
    return 0;
}