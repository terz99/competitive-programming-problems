#include <bits/stdc++.h>
using namespace std;

int maxHistogram(vector<int>& row){

    int n = row.size();

    int topVal;
    int currArea;
    int maxArea = 0;
    int i = 0;
    stack<int> s;

    while(i < n){

        if(s.empty() || row[s.top()] <= row[i]){
            s.push(i);
            i++;
        } else {

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

int solve(vector< vector<int> >& mat){

    int n = mat.size();
    int m = mat[0].size();

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

int main(){

    int cases;
    cin >> cases;
    while(cases--){
        
        int n, m;
        cin >> n >> m;
        vector< vector<int> > mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> mat[i][j];
            }
        }

        cout << solve(mat) << endl;
    }

    return 0;
}