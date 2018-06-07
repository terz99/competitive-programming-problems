#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    int minStickers(vector<string>& stickers, string target) {
        
        int n = target.length();
        vector<int> dp(1 << n, -1);
        dp[0] = 0;

        for(int state = 0; state < (1 << n); state++){

            if(dp[state] == -1) continue;
            for(int stickers_i = 0; stickers_i < stickers.size(); stickers_i++){

                string sticker = stickers[stickers_i];
                int now = state;
                for(int i = 0; i < sticker.length(); i++){
                    for(int j = 0; j < n; j++){
                        
                        if(((now >> j) & 1) == 1) continue;
                        if(target[j] == sticker[i]){
                            now |= (1 << j);
                            break;
                        }
                    }
                }

                if(dp[now] == -1 || dp[now] > dp[state] + 1){
                    dp[now] = dp[state] + 1;
                }
            }
        }

        return dp[(1 << n) - 1];
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