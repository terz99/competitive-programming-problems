#include <iostream>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;
    int i = 0;
    int j = 0;
    for(; i < (int)a.length() && a[i] == '0'; i++);
    for(; j < (int)b.length() && b[j] == '0'; j++);

    if((int)a.length()-i == (int)b.length()-j){
        for(; i < (int)a.length() && j < (int)b.length(); i++, j++){
            if(a[i] < b[j]){
                cout << "<" << endl;
                return 0;
            } else if(a[i] > b[j]){
                cout << ">" << endl;
                return 0;
            }
        }
        cout << "=" << endl;
    } else {
        cout << (((int)a.length()-i < (int)b.length()-j) ? "<" : ">") << endl;
    }

    return 0;
}