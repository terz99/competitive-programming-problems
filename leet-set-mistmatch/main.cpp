#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> freq(n+1, 0);
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        int duplicate, missing;
        for(int i = 1; i <= n; i++){
            if(freq[i] == 2){
                duplicate = i;
            } else if(freq[i] == 0){
                missing = i;
            }
        }

        vector<int> res;
        res.push_back(duplicate);
        res.push_back(missing);
        return res;
    }
};

int main(){
    return 0;
}