#include <bits/stdc++.h>
using namespace std;

class Solution {

    int check(vector<int>& sums, int diff){

        int res = 0;
        for(unsigned int i = 0; i < sums.size(); i++){
            res += upper_bound(sums.begin()+i, sums.end(), sums[i]+diff) - sums.begin() - i - 1;
        }
        return res;
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int l = INT_MAX;
        for(int i = 0; i < nums.size()-1; i++){
            l = min(l, nums[i+1]-nums[i]);
        }
        int r = nums[nums.size()-1] - nums[0];
        int res = r;
        while(l <= r){

            int mid = (l+r)/2;

            if(check(nums, mid) < k){
                l = mid+1;
            } else {
                res = mid;
                r = mid-1;
            }
        }
        return res;      
    }
};

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> sums(n);
    for(int i = 0; i < n; i++){
        cin >> sums[i];
    }

    Solution sol;
    cout << sol.smallestDistancePair(sums, k) << endl;

    return 0;
}