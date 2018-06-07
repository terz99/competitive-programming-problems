#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        if(gas.empty() || cost.empty() || gas.size() != cost.size()){
            return -1;
        }
        int n = (int)gas.size();
        int start = 0;
        int total = 0;
        int sumRemaining = 0;
        for(int i = 0; i < n; i++){

            int remaining = gas[i] - cost[i];
            if(sumRemaining >= 0){
                sumRemaining += remaining;
            } else {
                sumRemaining = remaining;
                start = i;
            }
            total += remaining;
        }

        if(total >= 0){
            return start;
        } else {
            return -1;
        }
    }
};

int main(){

    int n;
    cin >> n;
    vector<int> gas, cost;
    gas.resize(n);
    cost.resize(n);
    for(int i = 0; i < n; i++){
        cin >> gas[i];
    }
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }

    Solution sol;
    int res = sol.canCompleteCircuit(gas, cost);
    cout << res << endl;

    return 0;
}