#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4){
            return vector< vector<int> >();
        }
        sort(nums.begin(), nums.end());
        vector< vector<int> > res;
        

        ui i = 0;
        while(i < nums.size()-3){
            ui j = i+1;
            while(j < nums.size()-2){
                int l = j+1;
                int h = nums.size()-1;
                while(l < h){
                    int currSum = nums[i] + nums[j] + nums[l] + nums[h];
                    if(currSum == target){
                        res.push_back( {nums[i], nums[j], nums[l], nums[h]} );
                    }
                    if(currSum < target){
                        l++;
                        while(h > l && nums[l] == nums[l-1]) l++;
                    } else {
                        h--;
                        while(h > l && nums[h] == nums[h+1]) h--;
                    }
                }
                j++;
                while(nums[j-1] == nums[j] && j < nums.size()-2) j++;
            }
            i++;
            while(nums[i-1] == nums[i] && i < nums.size()-3) i++;
        }
        return res;
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){

    

    return 0;
}