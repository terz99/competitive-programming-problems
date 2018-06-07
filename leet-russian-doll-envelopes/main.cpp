#include <bits/stdc++.h>
using namespace std;

class Solution {

    static bool cmp(const pair<int, int>& a, const pair<int, int>& b){
        if(a.first == b.first){
            return a.second > b.second;
        } return a.first < b.first;
    }

public:
    int maxEnvelopes(vector< pair<int, int> >& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
        for(int i = 0; i < envelopes.size(); i++){

            auto itr = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if(itr == dp.end()){
                dp.push_back(envelopes[i].second);
            } else {
                *itr = envelopes[i].second;
            }
        }

        return dp.size();
    }
};

int main(){

    

    return 0;
}