#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;

int kadane(const vector<int>& arr){
    int max_end_here = 0;
    int max_so_far = INT_MIN;
    for(int el : arr){
        max_end_here += el;
        max_so_far = max(max_so_far, max_end_here);
        max_end_here = ((max_end_here < 0) ? 0 : max_end_here);
    }
    return max_so_far;
}

int solve(const vector< vector<int> >& mat){
    int row = mat.size();
    if(row == 0){
        return 0;
    }
    int col = mat[0].size();
    int res = INT_MIN;
    for(int l = 0; l < col; l++){
        vector<int> sums(row, 0);
        for(int r = l; r < col; r++){
            for(int i = 0; i < row; i++){
                sums[i] += mat[i][r];
            }
            res = max(res, kadane(sums));
        }
    }
    return res;
}

int main() {

    int num_cases;
    cin >> num_cases;
    while(num_cases--){

        int row, col;
        cin >> row >> col;
        vector< vector<int> > mat(row, vector<int>(col));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin >> mat[i][j];
            }
        }
        cout << solve(mat) << endl;
    }

	return 0;
}