#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
        int freq[260];
        memset(freq, 0, sizeof(freq));
        for(unsigned int i = 0; i < s.length(); i++){
            freq[s[i]]++;
        }

        vector< pair<int, char> > v;
        for(unsigned int i = 0; i < s.length(); i++){
            v.push_back( {freq[s[i]], s[i]} );
        }

        sort(v.rbegin(), v.rend());
        string res;
        for(unsigned int i = 0; i < v.size(); i++){
            res += v[i].second;
        }

        return res;
    }
};

int main(){

    string s;
    cin >> s;
    Solution sol;
    cout << sol.frequencySort(s) << endl;

    return 0;
}