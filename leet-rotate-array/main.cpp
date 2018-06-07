#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void rev(vector<int>& nums, int start, int end){

        while(start < end){
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }

    void rotate(vector<int>& nums, int k) {

        int n = (int)nums.size();
        if(k >= n){
            k = k%n;
        }

        rev(nums, 0, n-1);
        rev(nums, 0, k-1);
        rev(nums, k, n-1);
    }
};

int main(){

    int n, k;
    cin >> n >> k;
    vector<int> nums;
    nums.resize(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    Solution sol;
    sol.rotate(nums, k);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
