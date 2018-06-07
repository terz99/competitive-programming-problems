#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
cd ..
        int res = 0;
        int min = (1 << 30);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){

            int j = i + 1;
            int k = static_cast<int>(nums.size() - 1);
            while(j < k){

                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(sum-target);
                if(diff == 0) return sum;
                if(diff < min){
                    min = diff;
                    res = sum;
                }

                if(sum > target){
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
};

int main() {


    return 0;
}