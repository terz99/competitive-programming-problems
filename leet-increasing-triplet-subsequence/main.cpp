#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n = nums.size();
        int a, b, c;
        a = b = c = INT_MIN;

        for(int i = 0; i < n; i++){

            if(a == INT_MIN){
                a = nums[i];
                continue;
            }

            if(nums[i] <= a){
                a = nums[i];
                continue;
            }

            if(b == INT_MIN){
                b = nums[i];
                continue;
            }

            if(nums[i] <= b){
                b = nums[i];
                continue;
            }

            if(c == INT_MIN){
                c = nums[i];
                break;
            }
        }

        return (a != INT_MIN && b != INT_MIN && c != INT_MIN);
    }
};

int main(){

    srand(time(NULL));

    int n;
    // cin >> n;
    n = rand()%10 + 3;
    cout << n << endl;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        v[i] = rand()%11;
        cout << v[i] << " ";
    } cout << endl;

    Solution sol;
    cout << sol.increasingTriplet(v) << endl;

    return 0;
}