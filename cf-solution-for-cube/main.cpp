#include <iostream>
using namespace std;

int rot[][8] = {
    {2, 4, 6, 8, 10, 12, 23, 21}, 
    {1, 3, 5, 7, 9, 11, 24, 22}, 
    {1, 2, 18, 20, 12, 11, 15, 13}, 
    {3, 4, 17, 19, 10, 9, 16, 14}, 
    {15, 16, 7, 8, 19, 20, 23, 24}, 
    {13, 14, 5, 6, 17, 18, 21, 22}
};
int cube[25];
int newCube[25];

bool check(int rotIdx, int add){

    for(int i = 1; i <= 24; i++){
        newCube[i] = cube[i];
    }
    for(int i = 0; i < 8; i++){
        newCube[rot[rotIdx][i]] = cube[rot[rotIdx][(i+add+8)%8]];
    }
    // for(int i = 1; i <= 24; i++){
    //     cout << newCube[i] << " ";
    // }
    // cout << endl;

    for(int i = 1; i <= 24; i += 4){
        if(newCube[i] != newCube[i+1] || newCube[i] != newCube[i+2] || newCube[i] != newCube[i+3]){
            return false;
        }
    }
    return true;
}

int main(){

    for(int i = 1; i <= 24; i++){
        cin >> cube[i];
    }

    string ans = "NO";
    for(int i = 0; i < 6; i++){

        // rotate the i-th rotation
        if(check(i, 2) || check(i, -2)){
            ans = "YES";
            break;
        }
    }

    cout << ans << endl;

    return 0;
}