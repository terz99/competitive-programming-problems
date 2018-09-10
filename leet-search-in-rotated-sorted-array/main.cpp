#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()){
            return -1;
        }

        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(target == nums[mid]){
                return mid;
            }

            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid-1;
                } else {
                    low = mid+1;
                }
            } else {
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

int main(){
    return 0;
}