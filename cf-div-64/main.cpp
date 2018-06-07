#include <iostream>
using namespace std;

int main(){

    string s;
    cin >> s;
    bool isOne = false;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') isOne = true;
        if(isOne == true && s[i] == '0') cnt++;
    }

    cout << ((cnt >= 6) ? "yes" : "no") << endl;

    return 0;
}