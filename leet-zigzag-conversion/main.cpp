#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
        char mat[numRows+2][n+2];
        memset(mat, 0, sizeof(mat));
        int dx[] = {1, -1};
        int dy[] = {0, 1};
        int di = 0;
        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            mat[x][y] = s[i];
            x += dx[di];
            y += dy[di];
            if(x == numRows-1 || x == 0){
                di = (di+1)%2;
            }
        }
        string res;
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] != 0){
                    res += mat[i][j];
                }
            }
        }
        return res;
    }
};

int main(){
    string s;
    int num;
    cin >> s;
    cin >> num;
    Solution sol;
    cout << sol.convert(s, num) << endl;
    return 0;
}