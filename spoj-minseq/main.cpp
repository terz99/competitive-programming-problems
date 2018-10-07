#include <bits/stdc++.h>
using namespace std;

string ans, s1, s2;
int k, l;

void solve(int i, int j){
    if(i == s1.length()){
        for(int x = 0; x < s2.length(); x++){
            ans += s2[x];
            k++;
        }
    } else if(s1[i] < s2[j]){
        ans += s1[i];
        solve(i+1, j);
    } else if(s1[i] == s2[j]){
        string ans2;
        ans2 = ans;
        l = k;
        ans += s1[i]; k++;
        solve(i+1, j);

        for(int x = 0; x < s2.length(); x++){
            ans2 += s2[x];
            l++;
        }
        for(int x = i; x < s1.length(); x++){
            ans2 += s1[x];
            l++;
        }
        if(ans > ans2) ans = ans2;
    } else {
        for(int x = 0; x < s2.length(); x++){
            ans += s2[x];
            k++;
        }
        for(int x = i; x < s1.length(); x++){
            k++;
            ans += s1[x];
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while(cin >> s1 && cin >> s2){
        ans = "";
        k = l = 0;
        solve(0, 0);
        cout << ans << endl;
    }

    return 0;
}