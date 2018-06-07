#include <bits/stdc++.h>
using namespace std;

class Solution {

    void myswap(char& a, char& b){
        int tmp = a;
        a = b;
        b = tmp;
    }

public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);

        if(nums.empty())
            return -1;

        int i = nums.length()-1;
        while(i >= 1 && nums[i] <= nums[i-1])
            i--;
        
        if(i == 0)
            return -1;
        
        int j = nums.length()-1;
        while(nums[j] <= nums[i-1])
            j--;

        myswap(nums[j], nums[i-1]);
        reverse(nums.begin()+i, nums.end());

        long long res = stol(nums);
        if(res >= INT_MAX || res <= n)
            return -1;
        return (int)res;
    }
};

int main(){

    int n;
    cin >> n;
    Solution sol;
    cout << sol.nextGreaterElement(n) << endl;

    return 0;
}