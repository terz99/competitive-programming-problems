#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = INT_MIN;
        int max_ending_here = 0;
        for(int el : nums){
            max_ending_here += el;
            max_so_far = max(max_so_far, max_ending_here);
            max_ending_here = max(0, max_ending_here);
        }
        return max_so_far;
    }
};

static const auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){
    return 0;
}