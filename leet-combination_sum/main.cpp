#include <bits/stdc++.h>
using namespace std;

class Solution {

    void solve(const int& idx, const int& sum, vector<int>& curr_vec, set< vector<int> >& res, const vector<int>& candidates, const int& target){
        if(target == sum){
            res.insert(curr_vec);
            return;
        }
        for(unsigned int i = idx; i < candidates.size(); i++){
            if(sum + candidates[i] <= target){
                curr_vec.push_back(candidates[i]);
                solve(i, sum + candidates[i], curr_vec, res, candidates, target);
                curr_vec.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set< vector<int> > res;
        vector<int> curr_vec;
        solve(0, 0, curr_vec, res, candidates, target);
        vector< vector<int> > ret;
        for(auto v : res){
            ret.push_back(v);
        }
        return ret;
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int tar;
    cin >> tar;
    vector< vector<int> > res;
    Solution sol;
    res = sol.combinationSum(a, tar);
    for(auto v : res){
        for(auto el : v){
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}