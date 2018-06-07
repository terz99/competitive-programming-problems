#include <bits/stdc++.h>
using namespace std;

class Solution {

    int to_int(char c){
        return (int)(c);
    }

public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> last_occurance(260, -1);
        int ret = 0;
        string helper;
        int last_break = 0;

        for(int i = 0; i < s.length(); i++){

            int idx = to_int(s[i]);
            // cout << last_occurance[idx] << " ";
            if(last_occurance[idx] != -1){

                helper = s.substr(last_occurance[idx]+1, i-last_occurance[idx]-1);
                for(int j = last_break; j < last_occurance[idx]; j++){
                    int jdx = to_int(s[j]);
                    last_occurance[jdx] = -1;
                }
                last_break = last_occurance[idx]+1;
                last_occurance[idx] = i;
                helper += s[i];
            } else {
                helper += s[i];
                last_occurance[idx] = i;
            }

            // cout << helper << " " << last_occurance[idx] << endl;
            ret = max(ret, (int)helper.length());
        }

        return ret;
    }
};

int main(){
    return 0;
}