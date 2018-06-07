#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool check(int mid, int m, int n, int k){

        int cnt = 0;
        for(int i = 1; i <= m; i++){
            cnt += min(mid/i, n);
        }
        return cnt >= k;
    }

public:
    int findKthNumber(int m, int n, int k) {
        
        int l = 1;
        int h = m*n;
        int res = h;
        while(l <= h){

            int mid = (l+h)/2;
            if(check(mid, m, n, k)){
                res = mid;
                h = mid-1; 
            } else {
                l = mid+1;
            }
        } 
        return res;
    }
};

int main(){

    srand(time(NULL));
    int m, n, k;
    cin >> m >> n >> k;
    // m = rand()%10 + 1;
    // n = rand()%10 + 1;
    // k = rand()%(m*n) + 1;
    vector<int> v;
    cout << m << " " << n << " " << k << endl;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            v.push_back(i*j);
            cout << i*j << " ";
        }
        cout << endl;
    }
    sort(v.begin(), v.end());
    cout << v[k-1] << endl;
    Solution sol;
    cout << sol.findKthNumber(m, n, k) << endl;

    return 0;
}