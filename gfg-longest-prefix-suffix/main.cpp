#include <bits/stdc++.h>
using namespace std;

int findLPS(const string& pat){

    int n = pat.length();
    int lps[n];
    lps[0] = 0;
    int len = 0;
    int i = 1;

    while(i < n){

        if(pat[len] == pat[i]){

            len++;
            lps[i] = len;
            i++;
        } else {

            if(len != 0){
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps[n-1];
}

int main(){

    int cases;
    cin >> cases;
    while(cases--){

        string pat;
        cin >> pat;
        cout << findLPS(pat) << endl;
    }

    return 0;
}