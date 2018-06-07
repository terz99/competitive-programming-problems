#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_NODES = 1005;
const int MAX_LOG = 12;

int lca[MAX_LOG][MAX_NODES];
int level[MAX_NODES];
vector<int> graph[MAX_NODES];

void dfs(int curr, int prev){

	int next;

	for(int i = 1; i < MAX_LOG; i++){
		lca[i][curr] = lca[i-1][lca[i-1][curr]];
	}
	for(int i = 0; i < graph[curr].size(); i++){

		next = graph[curr][i];
		if(next == prev) continue;
		level[next] = level[curr] + 1;
		lca[0][next] = curr;
		dfs(next, curr);
	}
}

int find_lca(int u, int v){

	if(level[u] > level[v]) swap(u, v);

	for(int i = MAX_LOG-1; i >= 0; i--){
		if(level[v] - (1 << i) >= level[u]){
			v = lca[i][v];
		}
	}

	if(u == v){
		return u;
	}

	for(int i = MAX_LOG-1; i >= 0; i--){
		if(lca[i][v] != lca[i][u]){
			u = lca[i][u];
			v = lca[i][v];
		}
	}

	return lca[0][u];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num_children;
	int child;
	int num_cases;
	int num_nodes;
	int num_queries;
	cin >> num_cases;
	for(int c = 1; c <= num_cases; c++){

		cin >> num_nodes;

		// cleaning up
		for(int i = 0; i < num_nodes; i++){
			graph[i].clear();
		} 

		for(int i = 0; i < num_nodes; i++){

			cin >> num_children;

			for(int j = 0; j < num_children; j++){
				cin >> child;
				child--;
				graph[i].push_back(child);
				graph[child].push_back(i);
			}
		}

		memset(level, 0, sizeof(level));
		lca[0][0] = 0;
		dfs(0, -1);

		cin >> num_queries;

		cout << "Case " << c << ":\n";
		while(num_queries--){

			int u, v;
			cin >> u >> v;
			u--; v--;
			cout << find_lca(u, v) + 1 << "\n";
		}
	}

	return 0;
}