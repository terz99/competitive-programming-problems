#include <bits/stdc++.h>
using namespace std;

class Solution {

    void removeElementUtil(vector<int>& nums, int idx){
        for(unsigned int i = idx; i < nums.size()-1; i++){
            nums[i] = nums[i+1];
        }
        nums.resize(nums.size()-1);
        for(auto el : nums){
            cout << el << " ";
        }
        cout << endl;
    }

public:
    int removeElement(vector<int>& nums, int val) {
        int origLen = nums.size();
        int red = 0;
        for(unsigned int i = 0; i < nums.size(); i++){
            if(nums[i] == val){
                removeElementUtil(nums, i);
                red++;
            }
        }
        return origLen - red;      
    }
};

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);nums
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int val;
    cin >> val;
    Solution sol;
    cout << sol.removeElement(arr, val) << endl;
    for(auto el : arr){
        cout << el << " ";
    }
    cout << endl;

    return 0;
}