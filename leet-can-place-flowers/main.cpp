#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(unsigned int i = 0; i < flowerbed.size() && n > 0; i++){
            if(((i == 0) ? true : !flowerbed[i-1]) && ((i == flowerbed.size()-1) ? true : !flowerbed[i+1]) && !flowerbed[i]){
                flowerbed[i] = 1;
                n--;
            }
        }
        return n == 0;
    }
};

int main(){
    return 0;
}