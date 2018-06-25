#include <bits/stdc++.h>
using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {

    map<string, int> freq;
    for(auto el : strings){
        freq[el]++;
    }

    vector<int> res;
    for(int i = 0; i < (int)queries.size(); i++){
        res.push_back(freq[queries[i]]);
    }
    return res;
}