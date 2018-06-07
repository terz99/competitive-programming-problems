#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> res(n);
        for(int i = 2*n - 1; i >= 0; i--){
            while(!s.empty() && nums[s.top()] <= nums[i%n]){
                s.pop();
            }
            res[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }
        return res;
    }
};

int main(){
    return 0;
}