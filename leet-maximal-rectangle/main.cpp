#include <bits/stdc++.h>
using namespace std;

class Solution {

    int maxHistogram(vector<int> row){
    
        stack<int> s;
        int topVal = 0;
        int currArea;
        int maxArea = 0;

        int i = 0;
        while(i < row.size()){

            if(s.empty() || row[s.top()] <= row[i]){
                s.push(i);
                i++;
            } else{

                topVal = row[s.top()];
                s.pop();
                currArea = topVal*i;

                if(!s.empty()){
                    currArea = topVal*(i-s.top()-1);
                }
                maxArea = max(maxArea, currArea);
            }       
        }

        while(!s.empty()){

            topVal = row[s.top()];
            s.pop();
            currArea = topVal*i;
            if(!s.empty()){
                currArea = topVal*(i-s.top()-1);
            }
            maxArea = max(currArea, maxArea);
        }
        return maxArea;
    }

public:
    int maximalRectangle(vector< vector<char> >& matrix) {
        
        int n = matrix.size();
        if(n == 0) return 0;

        int m = matrix[0].size();
        if(m == 0) return 0;

        int sum[n+5][m+5];
        vector< vector<int> > mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mat[i][j] = (matrix[i][j] == '1');
            }
        }

        int res = maxHistogram(mat[0]);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j]){
                    mat[i][j] += mat[i-1][j];
                }
            }
            res = max(res, maxHistogram(mat[i]));
        }
        return res;
    }
};

int main(){

    int n, m;
    cin >> n >> m;
    vector< vector<char> > mat(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    Solution sol;
    cout << sol.maximalRectangle(mat) << endl;

    return 0;
}