#include <bits/stdc++.h>
using namespace std;

class Solution {

    vector<string> stickers;
    string target;
    int n;
    vector<int> dp;
    int finalState;

    int minStickers(int state){

        int& ret = dp[state];
        if(ret == -1){

            if(state == finalState){
                ret = 0;
            } else {

                for(auto sticker : stickers){

                    int now = state;
                    for(auto letter : sticker){

                        for(int i = 0; i < n; i++){
                            
                            if(((now >> i) & 1) == 1) continue;
                            if(letter == target[i]){
                                now |= (1 << i);
                                break;
                            }
                        }
                    }
                    if(now != state){
                        int alt = minStickers(now) + 1;
                        if(ret == -1 || ret > alt){
                            ret = alt;
                        }
                    }
                }
            }
        }
        return ret;
    }
    
    bool check(){
        
        vector<int> vis(26, 0);

        for(auto sticker : stickers){
            for(auto letter : sticker){
                vis[letter-'a']++;
            }
        }
        for(auto letter : target){
            if(!vis[letter-'a']){
                return false;
            }
        }

        return true;
    }

public:
    int minStickers(vector<string>& stickers, string target) {
        
        this->stickers = stickers;
        this->target = target;
        n = target.length();
        
        if(!check()){
            return -1;
        }
        
        finalState = (1 << n)-1;
        dp.resize((1 << n), -1);
        return minStickers(0);
    }
};

int main(){

    int n;
    cin >> n;
    vector<string> stickers(n);
    for(int i = 0; i < n; i++){
        cin >> stickers[i];
    }

    string target;
    cin >> target;

    Solution sol;
    cout << sol.minStickers(stickers, target);

    return 0;
}