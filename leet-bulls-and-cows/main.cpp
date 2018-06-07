#include <bits/stdc++.h>
using namespace std;

class Solution {

    int toInt(char c){
        return (int)(c-'0');
    }

    string toString(int x){

        if(x == 0){
            return "0";
        }

        string ret;
        while(x > 0){
            ret = (char)(x%10+'0') + ret;
            x /= 10;
        }
        return ret;
    }

public:
    string getHint(string secret, string guess) {
        
        int bulls = 0;
        int cows = 0;
        for(int i = 0; i < secret.size(); i++){
            if(i < guess.size() && secret[i] == guess[i]){
                bulls++;
            }
        }

        vector<int> freq(10, 0);
        for(int i = 0; i < secret.size(); i++){
            int num = toInt(secret[i]);
            if(i < guess.size()){
                if(secret[i] != guess[i]){
                    freq[num]++;
                }
            } else {
                freq[num]++;
            }
        }
        
        for(int i = 0; i < guess.size(); i++){
            int num = toInt(guess[i]);
            if(i < secret.size()){
                if(secret[i] != guess[i] && freq[num]){
                    freq[num]--;
                    cows++;
                }
            } else {
                if(freq[num]){
                    freq[num]--;
                    cows++;
                }
            }
        }
        
        return toString(bulls) + "A" + toString(cows) + "B";
    }
};

int main(){
    return 0;
}