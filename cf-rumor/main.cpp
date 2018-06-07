#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, 
    const vector< vector<int> >& edges, 
    const vector<long long>& gold, 
    vector<bool>& vis,
    long long& min_result){

    vis[curr] = true;
    min_result = min(min_result, gold[curr]);

    for(unsigned int i = 0; i < edges[curr].size(); i++){
        int next = edges[curr][i];
        if(!vis[next]){
            dfs(next, edges, gold, vis, min_result);
        }
    }
}

int main(){

    int n, m;
    cin >> n >> m;
    vector<long long> gold(n);
    vector< vector<int> > edges(n, vector<int>());
    vector<bool> vis(n, false);

    for(int i = 0; i < n; i++){
        cin >> gold[i];
    }

    for(int i = 0; i < m; i++){
        int guy1, guy2;
        cin >> guy1 >> guy2;
        guy1--; guy2--;
        edges[guy1].push_back(guy2);
        edges[guy2].push_back(guy1);
    }

    long long result = 0;
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            long long min_result = LONG_LONG_MAX;
            dfs(i, edges, gold, vis, min_result);
            result += min_result;
        }
    }

    cout << result << endl;

    return 0;
}