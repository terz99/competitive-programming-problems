#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int prod = 1;
        int prodR = 1;      
        for(auto el : nums){
            res.push_back(prod);
            prod *= el;
        }
        for(int i = res.size()-1; i >= 0; i--){
            res[i] *= prodR;
            prodR *= nums[i];
        }
        return res;
    }
};

int main(){
    return 0;
}