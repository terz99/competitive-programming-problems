#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxEndsHere = 1;
        int minEndsHere = 1;
        int res;
        int n = static_cast<int>(nums.size());

        for(int i = 0; i < n; i++){

            if(nums[i] > 0){
                maxEndsHere = maxEndsHere*nums[i];
                minEndsHere = min(minEndsHere*nums[i], 1);
            } else if(nums[i] == 0){
                maxEndsHere = 1;
                minEndsHere = 1;
            } else {
                int tmp = maxEndsHere;
                maxEndsHere = max(minEndsHere*nums[i], 1);
                minEndsHere = tmp*nums[i];
            }

            if(res < maxEndsHere){
                res = maxEndsHere;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}