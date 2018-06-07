#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_NODES = 100005;
const int MAX_LOG = 17;

int num_nodes;
int set_size;
int _set[MAX_NODES];
int parent[MAX_NODES];
int lvl[MAX_NODES];
int lca[MAX_LOG][MAX_NODES];
vector<int> graph[MAX_NODES];

void preprocess_tree(){

	for(int i = 0; (1 << i) < num_nodes; i++){
		for(int j = 0; j < num_nodes; j++){
			lca[i][j] = -1;
		}
	}

	for(int i = 0; i < num_nodes; i++){
		lca[0][i] = parent[i];
	}

	for(int i = 1; i < MAX_LOG; i++){
		for(int j = 0; j < num_nodes; j++){
			if(lca[i-1][j] != -1){
				lca[i][j] = lca[i-1][lca[i-1][j]];
			}
		}
	}
}

void find_levels(int curr){

	for(int i = 0; i < graph[curr].size(); i++){
		int next = graph[curr][i];
		lvl[next] = lvl[curr] + 1;
		find_levels(next);
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
			u = lca[i][u];
			v = lca[i][v];
		}
	}

	return lca[0][u];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num_nodes;
	for(int i = 1; i < num_nodes; i++){
		cin >> parent[i];
		graph[parent[i]].push_back(i);
	}
	parent[0] = -1;

	cin >> set_size;
	for(int i = 0; i < set_size; i++){
		cin >> _set[i];
	}

	preprocess_tree();
	find_levels(0);

	if(set_size == 1){
		cout << _set[0] << "\n";
	} else {
		int res = find_lca(_set[0], _set[1]);
		for(int i = 2; i < set_size; i++){
			res = find_lca(res, _set[i]);
		}
		cout << res << "\n";
	}

	return 0;
}