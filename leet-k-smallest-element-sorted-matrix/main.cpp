#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool check(int mid, vector< vector<int> >& mat, int k){

        int n = mat.size();
        int m = mat[0].size();
        int x = 0;
        int y = m-1;
        int res = 0;
        while(x < n && y >= 0){

            if(mid >= mat[x][y]){
                res += (y+1);
                x++; 
            } else {
                y--;
            }
        }
        return res >= k;
    }

public:
    int kthSmallest(vector< vector<int> >& matrix, int k) {
        
        long long l = INT_MIN;
        long long r = INT_MAX;
        long long res = r;
        while(l <= r){

            long long mid = (l+r)/2ll;
            if(check(mid, matrix, k)){
                res = mid;
                r = mid-1ll;
            } else {
                l = mid+1ll;
            }
        }
        return res;
    }
};


int main(){

    int n, m;
    cin >> n >> m;
    vector< vector<int> > mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    int k;
    cin >> k;

    Solution sol;
    cout << sol.kthSmallest(mat, k) << endl;

    return 0;
}