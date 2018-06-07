#include <bits/stdc++.h>
using namespace std;

int num_nodes, num_edges;
int draw;
vector<int> adj[200005];
int par[200005][2];
bool dis[200005][2];
bool vis[200005]; 

void dfs(int curr, int parity, int parent){

    vis[curr] = true;
    dis[curr][parity] = true;
    par[curr][parity] = parent;

    for(unsigned int i = 0; i < adj[curr].size(); i++){
        int next = adj[curr][i];
        int new_parity = parity^1;
        if(!dis[next][new_parity]){
            dfs(next, new_parity, curr);
        } else {
            draw |= vis[next];
        }
    }

    vis[curr] = false;
}

int main(){

    cin >> num_nodes >> num_edges;
    for(int i = 1; i <= num_nodes; i++){

        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int to;
            cin >> to;
            adj[i].push_back(to);
        }
    }

    int start;
    cin >> start;

    dfs(start, 0, 0);

    for(int i = 1; i <= num_nodes; i++){

        if(adj[i].empty() && dis[i][1]){
        
            cout << "Win\n";
            vector<int> path;
            for(int j = 1; i != 0; i = par[i][j], j ^= 1){
                path.push_back(i);
            }
            for(int j = path.size()-1; j >= 0; j--){
                cout << path[j] << " ";
            }
            cout << endl;
            return 0;
        }

    }

    cout << ((draw) ? "Draw" : "Lose") << endl;

    return 0;
}
