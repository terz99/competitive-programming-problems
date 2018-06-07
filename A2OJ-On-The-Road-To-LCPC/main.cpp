#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100005;
const int MAX_LOG = 17;

int num_nodes;
int num_queries;
vector<int> graph[MAX_NODES];
int lvl[MAX_NODES];
int lca[MAX_LOG][MAX_NODES];
int num_cases;

void dfs(int curr, int prev){

	for(int i = 1; i < MAX_LOG; i++){
		if(lca[i-1][curr] != -1){
			lca[i][curr] = lca[i-1][lca[i-1][curr]];
		}
	}

	for(int i = 0; i < graph[curr].size(); i++){

		int next = graph[curr][i];
		if(next == prev) continue;
		lvl[next] = lvl[curr] + 1;
		lca[0][next] = curr;
		dfs(next, curr);
	}
}

int find_lca(int u, int v){

	if(lvl[u] > lvl[v]) swap(u, v);

	for(int i = MAX_LOG-1; i >= 0; i--){
		if(lvl[v] - (1 << i) >= lvl[u]){
			v = lca[i][v];
		}
	}

	if(u == v) return u;

	for(int i = MAX_LOG-1; i >= 0; i--){
		if(lca[i][v] != lca[i][u]){
			v = lca[i][v];
			u = lca[i][u];
		}
	}

	return lca[0][u];
}

int get_dist(int u, int v){
	int LCA = find_lca(u, v);
	return lvl[u] + lvl[v] - 2*lvl[LCA];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num_cases;


	for(int c = 1; c <= num_cases; c++){

		cout << "Case " << c << ":\n";

		cin >> num_nodes >> num_queries;

		for(int i = 0; i < num_nodes; i++){
			graph[i].clear();
			lvl[i] = 0;
		}
		for(int i = 0; (1 << i) < num_nodes; i++){
			for(int j = 0; j < num_nodes; j++){
				lca[i][j] = -1;
			}
		}

		for(int i = 1; i < num_nodes; i++){
			int from, to;
			cin >> from >> to;
			from--; to--;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}

		lca[0][0] = 0;
		dfs(0, -1);

		int u, v;
		while(num_queries--){

			cin >> u >> v;
			u--; v--;
			cout << get_dist(u, v) << "\n";
		}

	}

	return 0;
}