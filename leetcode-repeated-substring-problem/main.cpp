#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findAllDivisors(int n){

    vector<int> res;
    for(int i = 1; i <= sqrt(n)+1; i++){
        if(n%i == 0){
            res.push_back(i);
        }
    }
    return res;
}

int main(){

    string s;
    cin >> s;
    int len = s.length();
    vector<int> divisors = findAllDivisors(len);
    for(int i = 0; i < (int)divisors.size(); i++){

        int curr_div = divisors[i];
        string cmp = "";
        for(int j = 0; j < curr_div; j++){
            cmp += s[j];
        }
        string help = "";
        for(int i = 0; i < len; i += curr_div){
            help += cmp;
        }
        if(help == s){
            cout << "True\n";
            return 0;
        }
    }
    cout << "False\n";

    return 0;
}