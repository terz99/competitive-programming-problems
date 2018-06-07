#include <bits/stdc++.h>
using namespace std;

void computeLPS(const string& pat, const int& m, int lps[]){

    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i < m){

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
}

void kmp(const string& txt, const string& pat){

    int n = txt.length();
    int m = pat.length();

    int lps[m];
    computeLPS(pat, m, lps);

    int i = 0;
    int j = 0;
    while(i < n){

        if(txt[i] == pat[j]){
            j++;
            i++;
        }

        if(j == m){
            cout << "Found pattern at " << i-j << endl;
            j = lps[j-1];
        } else if(i < n && pat[j] != txt[i]){

            if(j != 0){
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
}

int main(){

    string pat, txt;
    cin >> txt >> pat;
    kmp(txt, pat);    

    return 0;
}