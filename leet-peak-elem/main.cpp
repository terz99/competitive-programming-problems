#include <bits/stdc++.h>
using namespace std;

class Solution {

    int findPeakElement(vector<int>& nums, int l, int r){

        if(l == r){
            return l;
        }

        int mid = (l+r)/2;
        int leftElem = mid == 0 ? INT_MIN : nums[mid-1];
        int rightElem = mid == nums.size()-1 ? INT_MIN : nums[mid+1];
        if(nums[mid] > leftElem && nums[mid] > rightElem){
            return mid;
        } else if(nums[mid] < leftElem){
            return findPeakElement(nums, l, mid-1);
        } else {
            return findPeakElement(nums, mid+1, r);
        }
    }

public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums, 0, nums.size()-1);
    }
};

int main(){

    return 0;
}