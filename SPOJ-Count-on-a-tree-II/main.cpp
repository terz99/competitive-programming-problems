#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX_NODES = 40005;
const int MAX_LOG = 19;
const int MAX_QUERIES = 100005;

struct query{

	int left_idx;
	int right_idx;
	int query_idx;
	int block;
	int lca;

	query(){}

	bool operator<(const query &q)const{
		if(block == q.block) return right_idx < q.right_idx;
		return block < q.block;
	}
};

query queries[MAX_QUERIES];
int from, to, curr_left, curr_right, LCA;
int uni;
int tmp[MAX_NODES];
int res;
int ans[MAX_QUERIES];
int block_size;
int level[MAX_NODES];
int num_nodes;
int num_queries;
int a[MAX_NODES];
int lca[MAX_LOG][MAX_NODES];
int global_time;
int start_time[MAX_NODES], end_time[MAX_NODES];
int id[MAX_NODES << 1];
int val[MAX_NODES];
bool vis[MAX_NODES];
vector<int> edges[MAX_NODES];

void dfs(int curr_node, int par_node){

	start_time[curr_node] = global_time;
	id[global_time] = curr_node;
	global_time++;
	for(int i = 1; i < MAX_LOG; i++){
		lca[i][curr_node] = lca[i-1][lca[i-1][curr_node]];
	}

	for(int i = 0; i < edges[curr_node].size(); i++){

		int next_node = edges[curr_node][i];
		if(next_node == par_node) continue;
		level[next_node] = level[curr_node] + 1;
		lca[0][next_node] = curr_node;
		dfs(next_node, curr_node);
	}

	end_time[curr_node] = global_time;
	id[global_time] = curr_node;
	global_time++;
}

int find_lca(int u, int v){

	if(level[u] > level[v]) swap(u, v);
	for(int i = MAX_LOG-1; i >= 0; i--){
		if(level[v] - (1 << i) >= level[u]){
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

void check(int x){
	if(vis[x] && (--val[a[x]] == 0)) res--;
	else if(!vis[x] && (val[a[x]]++ == 0)) res++;
	vis[x] ^= 1;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int u, v, i;

	while(scanf("%d %d", &num_nodes, &num_queries) != EOF){

		// cleaning up
		memset(vis, false, sizeof(vis));
		memset(val, 0, sizeof(val));
		global_time = 0;
		for(i = 0; i < num_nodes; i++) edges[i].clear();


		//cin >> num_nodes >> num_queries;
		// input of the array
		for(i = 0; i < num_nodes; i++){
			cin >> a[i];
			tmp[i] = a[i];
		}

		// compressing the array
		sort(tmp, tmp+num_nodes);
		uni = unique(tmp, tmp+num_nodes) - tmp - 1;
		for(i = 0; i < num_nodes; i++){
			a[i] = lower_bound(tmp, tmp+uni, a[i]) - tmp;
		}

		// input edges
		for(i = 1; i < num_nodes; i++){

			cin >> from;
			cin >> to;
			from--;
			to--;

			edges[from].push_back(to);
			edges[to].push_back(from);
		}

		// preprocess
		// dfs and find LCA of every node
		lca[0][0] = 0;
		dfs(0, -1);
		block_size = sqrt(global_time)+1;

		// input queries
		for(i = 0; i < num_queries; i++){

			cin >> u;
			cin >> v;
			u--;
			v--;
			LCA = find_lca(u, v);
			if(start_time[u] > start_time[v]) swap(u, v);
			if(LCA == u){
				queries[i].left_idx = start_time[u];
				queries[i].right_idx = start_time[v];
			} else {
				queries[i].left_idx = end_time[u];
				queries[i].right_idx = start_time[v];
			}
			queries[i].query_idx = i;
			queries[i].block = queries[i].left_idx/block_size;
			queries[i].lca = LCA;
		}

		sort(queries, queries + num_queries);

		curr_left = queries[0].left_idx;
		curr_right = queries[0].left_idx-1;
		res = 0;

		for(i = 0; i < num_queries; i++){

			while(curr_left < queries[i].left_idx) check(id[curr_left++]);
			while(curr_left > queries[i].left_idx) check(id[--curr_left]);
			while(curr_right < queries[i].right_idx) check(id[++curr_right]);
			while(curr_right > queries[i].right_idx) check(id[curr_right--]);

			if(queries[i].lca != id[curr_left] && queries[i].lca != id[curr_right]){
				check(queries[i].lca);
			}
			ans[queries[i].query_idx] = res;
			if(queries[i].lca != id[curr_left] && queries[i].lca != id[curr_right]){
				check(queries[i].lca);
			}
 		}

 		for(i = 0; i < num_queries; i++){
 			cout << ans[i] << "\n";
 		}
	}

	return 0;
}