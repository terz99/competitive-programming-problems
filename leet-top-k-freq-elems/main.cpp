#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> res;

        map<int, int> freq;
        for(int i = 0; i < nums.size(); i++){
            freq[nums[i]]++;
        }

        set< pair<int, int> > sol;
        for(int i = 0; i < nums.size(); i++){
            sol.insert( {freq[nums[i]], nums[i]} );
        }

        set< pair<int, int> >::iterator it = sol.end();
        it--;
        for(; k > 0; it--, k--){
            pair<int, int> p = *it;
            res.push_back(p.second);
        }

        return res;
    }
};

int main(){

    int n, k;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> k;

    Solution sol;
    vector<int> res = sol.topKFrequent(a, k);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    } cout << endl;

    return 0;
}