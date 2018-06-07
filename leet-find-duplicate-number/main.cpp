#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++){

            if(nums[abs(nums[i])] > 0){
                nums[abs(nums[i])] = -nums[abs(nums[i])];
            } else {
                return -nums[abs(nums[i])];
            }
        }
    }
};

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    Solution sol;
    cout << sol.findDuplicate(a);

    return 0;
}