#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_NODES = 200005;
const int MAX_LOG = 19;
const int INF = (1 << 30);

int num_nodes;
int num_queries;
int lca[MAX_LOG][MAX_NODES];
int lvl[MAX_NODES];
vector<int> graph[MAX_NODES];

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

	if(lvl[u] > lvl[v]){
		int tmp = u;
		u = v;
		v = tmp;
	}

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

int get_dist(int u, int v){
	int LCA = find_lca(u, v);
	return (lvl[u] - lvl[LCA]) + (lvl[v] - lvl[LCA]); 
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num_nodes;
	for(int i = 1; i < num_nodes; i++){
		int from, to;
		cin >> from >> to;
		from--; to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for(int i = 0; (1 << i) < num_nodes; i++){
		for(int j = 0; j < num_nodes; j++){
			lca[i][j] = -1;
		}
	}

	lca[0][0] = 0;
	dfs(0, -1);

	cin >> num_queries;
	while(num_queries--){

		int res;
		int curr;
		int LCA;
		int cmp = INF;
		int r, u, v;
		cin >> r >> u >> v;
		r--; v--; u--;

		// check if the root is r
		curr = get_dist(r, u) + get_dist(r, v);
		if(curr < cmp){
			cmp = curr;
			res = r;
		}

		// check if the root is u
		curr = get_dist(u, r) + get_dist(u, v);
		if(curr < cmp){
			cmp = curr;
			res = u;
		}

		// check if the root is v
		curr = get_dist(v, r) + get_dist(v, u);
		if(curr < cmp){
			cmp = curr;
			res = v;
		}

		// check if the root is lca(r, u)
		LCA = find_lca(r, u);
		curr = get_dist(LCA, r) + get_dist(LCA, u) + get_dist(LCA, v);
		if(curr < cmp){
			cmp = curr;
			res = LCA;
		}

		// check if the root is lca(r, v)
		LCA = find_lca(r, v);
		curr = get_dist(LCA, r) + get_dist(LCA, u) + get_dist(LCA, v);
		if(curr < cmp){
			cmp = curr;
			res = LCA;
		}

		// check if root is lca(v, u)
		LCA = find_lca(u, v);
		curr = get_dist(LCA, r) + get_dist(LCA, u) + get_dist(LCA, v);
		if(curr < cmp){
			cmp = curr;
			res = LCA;
		}

		cout << res+1 << "\n";
	}

	return 0;
}