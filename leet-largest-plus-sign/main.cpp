#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector< vector<int> >& mines) {
        
        vector< vector<int> > grid(N, vector<int>(N, 1));
        vector< vector<int> > l(N, vector<int>(N, 0)), r(N, vector<int>(N, 0)), d(N, vector<int>(N, 0)), u(N, vector<int>(N, 0));

        for(int i = 0; i < mines.size(); i++){
            grid[mines[i][0]][mines[i][1]] = 0;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << grid[i][j];
            } cout << endl;
            // This loop has debugging role
        }

        // calculating left
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(j == 0){
                    l[i][j] = grid[i][j];
                } else {
                    l[i][j] = ((grid[i][j] == 0) ? 0 : l[i][j-1] + 1);
                }
            }
        }

        // calculating right
        for(int i = 0; i < N; i++){
            for(int j = N-1; j >= 0; j--){
                if(j == N-1){
                    r[i][j] = grid[i][j];
                } else {
                    r[i][j] = ((grid[i][j] == 0) ? 0 : r[i][j+1] + 1);
                }
            }
        }

        // calulating up
        for(int j = 0; j < N; j++){
            for(int i = 0; i < N; i++){
                if(i == 0){
                    u[i][j] = grid[i][j];
                } else {
                    u[i][j] = ((grid[i][j] == 0) ? 0 : u[i-1][j] + 1);
                }
            }
        }

        // calculating down
        for(int j = 0; j < N; j++){
            for(int i = N-1; i >= 0; i--){
                if(i == N-1){
                    d[i][j] = grid[i][j];
                } else {
                    d[i][j] = ((grid[i][j] == 0) ? 0 : d[i+1][j] + 1);
                }
            }
        }

        // calculating the order
        int res = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){

                int horizontal = min(l[i][j], r[i][j]);
                int vertical = min(u[i][j], d[i][j]);
                res = max(res, min(horizontal, vertical));
            }
        }

        return res;
    }
};

int main(){

   int n, m;
   cin >> n >> m;
   vector< vector<int> > mines(m, vector<int>(2));
   for(int i = 0; i < m; i++){
       for(int j = 0; j < 2; j++){
           cin >> mines[i][j];
       }
   }

   Solution sol;
   cout << sol.orderOfLargestPlusSign(n, mines) << endl;

    return 0;
}