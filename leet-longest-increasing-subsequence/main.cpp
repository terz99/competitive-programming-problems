#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> dp;

        for(int i = 0; i < nums.size(); i++){

            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            if(it == dp.end()){
                dp.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }

        return dp.size();
    }
};

int main(){

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    Solution sol;
    cout << sol.lengthOfLIS(v) << endl;

    return 0;
}