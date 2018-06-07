#include <bits/stdc++.h>
using namespace std;

class Solution {

private:

    class BitMap{

    public:
        int len;
        int bm;
        BitMap(){
            len = 0;
            bm = 0;
        }
    };

    int getIndex(char  c){
        return (int)(c-'a');
    }

public:
    
    int maxProduct(vector<string>& words) {

        int res = 0;
        int n = (int)words.size();
        if(n == 0){
            return res;
        }
        BitMap bms[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < (int)words[i].length(); j++){
                int idx = getIndex(words[i][j]);
                bms[i].bm |= (1 << idx);
            }
            bms[i].len = (int)words[i].length();
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!(bms[i].bm & bms[j].bm)){
                    res = max(res, bms[i].len*bms[j].len);
                }
            }
        }
        return res;
    }
};

int main(){

    int n;
    cin >> n;
    vector<string> words;
    words.resize(n);
    for(int i = 0; i < n; i++){
        cin >> words[i];
    }

    Solution sol;
    int res = sol.maxProduct(words);
    cout << res << endl;

    return 0;
}