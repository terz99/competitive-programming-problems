#include <bits/stdc++.h>
using namespace std;

class Solution {

    int count(int n){
        return (n*(n+1))/2;
    }

public:
    int candy(vector<int>& ratings) {
        if(ratings.size() <= 1){
            return ratings.size();
        }

        int old_slope = 0;
        int up = 0;
        int down = 0;
        int res = 0;
        for(int i = 1; i < ratings.size(); i++){

            int new_slope = ((ratings[i] > ratings[i-1]) ? 1 : (ratings[i] < ratings[i-1]) ? -1 : 0);
            if((old_slope > 0 && new_slope == 0) || (old_slope < 0 && new_slope >= 0)){
                res += count(up) + count(down) + max(up, down);
                up = down = 0;
            }
            if(new_slope < 0){
                down++;
            }
            if(new_slope > 0){
                up++;
            }
            if(new_slope == 0){
                res++;
            } 
            old_slope = new_slope;
        }
        res += count(up) + count(down) + max(up, down) + 1;
        return res;      
    }
};

int main(){
    return 0;
}