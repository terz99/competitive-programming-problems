/**
@author     Dushan Terzikj

@since      1.0.0
@version    1.0.0
*/
#include <bits/stdc++.h>
using namespace std;

class Elem{
public:
    int data;
    int x, y;
    Elem(){}
    Elem(const int& data, const int& x, const int& y){
        this->data = data;
        this->x = x;
        this->y = y;
    }

    bool operator<(const Elem& e) const{
        return this->data > e.data;
    }
};

// class compare{
// public:
//     bool operator()(const Elem& a, const Elem& b){
//         return a.data < b.data;
//     }
// };

int kthSmallestElement(const vector< vector<int> >& mat, int k){
    int n = mat.size();
    vector<Elem> v;
    for(int i = 0; i < n; i++){
        Elem tmp(mat[0][i], 0, i);
        v.push_back(tmp);
    }
    priority_queue<Elem> q(less<Elem>(), v);
    int last;
    while(k--){
        Elem tmp = q.top();
        q.pop();
        last = tmp.data;
        if(tmp.x + 1 < n){
            q.push( Elem(mat[tmp.x+1][tmp.y], tmp.x+1, tmp.y) );
        }
    }
    return last;
}

int main(){

    int n;
    cin >> n;
    vector< vector<int> > mat(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    int k;
    cin >> k;

    cout << kthSmallestElement(mat, k) << endl;

    return 0;
}
