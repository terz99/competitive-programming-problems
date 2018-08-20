#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector< vector<int> >& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int res = INT_MIN;   
        for(int l = 0; l < col; l++){
            vector<int> sums(row, 0);
            for(int r = l; r < col; r++){
                for(int i = 0; i < row; i++){
                    sums[i] += matrix[i][r];
                }

                set<int> cumSet;
                cumSet.insert(0);
                int currSum = 0, maxSum = INT_MIN;
                for(auto sum : sums){
                    currSum += sum;
                    set<int>::iterator it = cumSet.lower_bound(currSum - k);
                    if(it != cumSet.end()){
                        maxSum = max(maxSum, currSum - *it);
                    }
                    cumSet.insert(currSum);
                }
                res = max(maxSum, res);
            }
        }
        return res;
    }
};

int main(){
    
}