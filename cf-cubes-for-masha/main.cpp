#include <iostream>
#include <set>
#include <cstdlib>
using namespace std;

set<int> s;
bool vis[3];
int num_cubes;
int nums[3][6];

void gen(int num){

    for(int i = 0; i < num_cubes; i++){

        if(vis[i]) continue;

        vis[i] = true;
        for(int j = 0; j < 6; j++){
            if(num*10 + nums[i][j] != 0)
                s.insert(num*10 + nums[i][j]);
            gen(num*10 + nums[i][j]);
        }
        vis[i] = false;
    }
}

int main(){

    cin >> num_cubes;
    for(int i = 0; i < num_cubes; i++){
        for(int j = 0; j < 6; j++){
            cin >> nums[i][j];
        }
    }

    gen(0);
    int last = -1;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++){

        if(last == -1){
            if(*it != 1){
                cout << 0 << endl;
                return 0;
            } else {
                last = *it;
                continue;
            }
        }
        if(*it - last == 1){
            last = *it;
        } else {
            break;
        }
    }
    cout << last << endl;
    return 0;
}