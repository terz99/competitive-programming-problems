#include <bits/stdc++.h>
using namespace std;

class Solution {

private:

    const int REACHED = -(1 << 30);

    bool outOfBounds(int x, int y, int n, int m){
        return (x < 0 || x >= n || y < 0 || y >= m);
    }

public:

    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;
        if((int)matrix.size() == 0 || (int)matrix[0].size() == 0){
            return res;
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int currDir = 0;
        int cnt = 0;
        int n = (int)matrix.size();
        int m = (int)matrix[0].size();
        int i, j;
        i = j = 0;
        while(cnt < n*m){

            cnt++;
            res.push_back(matrix[i][j]);
            matrix[i][j] = REACHED;
            int nextI = i + dx[currDir];
            int nextJ = j + dy[currDir];
            if(outOfBounds(nextI, nextJ, n, m) || matrix[nextI][nextJ] == REACHED){
                currDir = (currDir+1)%4;
                nextI = i + dx[currDir];
                nextJ = j + dy[currDir];
            }
            i = nextI;
            j = nextJ;
        }

        return res;
    }
};

int main() {

    int n, m;
    cin >> n >> m;
    vector< vector<int> > matrix;
    matrix.resize(n);
    for(int i = 0; i < n; i++){
        matrix[i].resize(m);
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    Solution sol;
    vector<int> res = sol.spiralOrder(matrix);
    for(int i = 0; i < (int)res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}