#include <bits/stdc++.h>
using namespace std;

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {

    vector< pair<int, long> > v;
    for(int i = 0; i < queries.size(); i++){
        int a = queries[i][0];
        int b = queries[i][1];
        long k = queries[i][2];
        v.push_back({a, k});
        v.push_back({b+1, -k});
    }

    long res = INT_MIN;
    long sum = 0;
    sort(v.begin(), v.end());
    for(auto p : v){
        sum += p.second;
        res = max(res, sum);
    }
    return res;
}

int main(){

    int n, m;
    cin >> n >> m;
    vector< vector<int> > queries(m, vector<int>(3));
    for(int i = 0; i < n; i++){
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    cout << arrayManipulation(n, queries) << endl;

    return 0;
}