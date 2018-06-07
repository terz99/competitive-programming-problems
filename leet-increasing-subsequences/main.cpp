#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector< vector<int> > findSubsequences(vector<int>& nums) {
        
        if(nums.size() <= 1){
            return vector< vector<int> >();
        }

        set< vector<int> > s;
        vector<int> v;
        findSubsequences(nums, v, s, 0);
        vector< vector<int> > res;

        for(auto i = s.begin(); i != s.end(); i++){

            v = *i;
            for(int j = 0; j < v.size(); j++){
                cout << v[j] << " ";
            }
            cout << endl;
            res.push_back(v);
        }

        return res;
    }

private:

    void findSubsequences(vector<int>& nums, vector<int>& v, set< vector<int> >& s, int idx){

        if(v.size() >= 2){
            s.insert(v);
        }

        if(idx == nums.size()){
            return;
        }

        for(int i = idx; i < nums.size(); i++){

            if(v.empty()){
                v.push_back(nums[i]);
            } else if(v[v.size()-1] <= nums[i]){
                v.push_back(nums[i]);
            } else {
                continue;
            }
            findSubsequences(nums, v, s, i+1);
            v.pop_back();
        }
    }
};

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution sol;
    vector< vector<int> > res = sol.findSubsequences(arr);

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        } cout << endl;
    }

    return 0;
}