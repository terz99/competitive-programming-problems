#include <bits/stdc++.h>
using namespace std;

static const auto ios_base_sync_off = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = int(height.size()-1);
        int res = (j - i)*min(height[i], height[j]);
        while(i < j){
            if(height[i] < height[j]){
                i++;
            } else {
                j--;
            }
            int currVal = (j-i)*min(height[i], height[j]);
            res = max(res, currVal);
        }
        return res;
    }
};