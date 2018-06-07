#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100005;
const int MAX_QUERIES = 10005;
const int MAX_LOG = 17;
const int MAX_COLORS = 15;

struct query{

	int l, r;
	int block;
	int lca;
	int idx;

	query(){}

	bool operator<(const query &q)const{
		if(block == q.block) return r < q.r;
		return block < q.block;
	}
};

query queries[MAX_QUERIES];
int lca[MAX_LOG][MAX_NODES];
int lvl[MAX_NODES];
int global_time;
int start_time[MAX_NODES], end_time[MAX_NODES];
int id[MAX_NODES << 1];
int num_nodes;
int num_queries;
long long val[MAX_NODES];
int color[MAX_NODES];
long long ans[MAX_QUERIES];
long long total_color[MAX_COLORS];
bool vis[MAX_NODES];
vector<int> graph[MAX_NODES];
deque<long long> used[MAX_COLORS];

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

void dfs(int curr, int prev){

	start_time[curr] = global_time;
	id[global_time] = curr;
	global_time++;

	for(int i = 1; i < MAX_LOG; i++){
		if(lca[i-1][curr] != -1){
			lca[i][curr] = lca[i-1][lca[i-1][curr]];
		}
	}

	int next;
	for(int i = 0; i < graph[curr].size(); i++){

		next = graph[curr][i];
		if(next == prev) continue;
		lvl[next] = lvl[curr] + 1;
		lca[0][next] = curr;
		dfs(next, curr);
	}

	end_time[curr] = global_time;
	id[global_time] = curr;
	global_time++;
}

long long get_val(int x, int y){
	return (val[x]-val[y])*(val[x]-val[y]);
}

void erase_right(int x){

	int c = color[x];
	used[c].pop_back();

	if(!used[c].empty()){
		total_color[c] -= get_val(x, used[c].back());
	}
}

void erase_left(int x){

	int c = color[x];
	used[c].pop_front();

	if(!used[c].empty()){
		total_color[c] -= get_val(x, used[c].front());
	}
}

void insert_right(int x){

	int c = color[x];
	if(!used[c].empty()){
		total_color[c] += get_val(x, used[c].back());
	}
	used[c].push_back(x);
}

void insert_left(int x){

	int c = color[x];
	if(!used[c].empty()){
		total_color[c] += get_val(x, used[c].front());
	}
	used[c].push_front(x);
}

void check_right(int x){

	if(vis[x]){
		erase_right(x);
	} else {
		insert_right(x);
	}
	vis[x] ^= 1;
}

void check_left(int x){

	if(vis[x]){
		erase_left(x);
	} else {
		insert_left(x);
	}
	vis[x] ^= 1;
}

long long get_answer(int LCA){

	long long res = 0;
	for(int i = 0; i < MAX_COLORS; i++){
		if(i == color[LCA]) continue;
		res += total_color[i];
	}
	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> num_nodes;
	for(int i = 0; i < num_nodes; i++){
		cin >> color[i];
	}
	for(int i = 0; i < num_nodes; i++){
		cin >> val[i];
	}
	int from, to;
	for(int i = 1; i < num_nodes; i++){
		cin >> from >> to;
		from--; to--;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for(int i = 0; i < num_nodes; i++){
		sort(graph[i].begin(), graph[i].end());
	}

	for(int i = 0; (1 << i) < num_nodes; i++){
		for(int j = 0; j < num_nodes; j++){
			lca[i][j] = -1;
		}
	}

	lca[0][0] = 0;
	dfs(0, -1);

	cin >> num_queries;
	int u, v;
	int block_size = sqrt(global_time) + 1;
	for(int i = 0; i < num_queries; i++){

		cin >> u >> v;
		u--; v--;
		if(start_time[u] > start_time[v]) swap(u, v);
		queries[i].lca = find_lca(u, v);
		if(queries[i].lca == u){
			queries[i].l = start_time[u];
			queries[i].r = start_time[v];
		} else {
			queries[i].l = end_time[u];
			queries[i].r = start_time[v];
		}

		queries[i].block = queries[i].l/block_size;
		queries[i].idx = i;
	}

	sort(queries, queries + num_queries);

	int curr_left = queries[0].l;
	int curr_right = queries[0].l-1;

	for(int i = 0; i < num_queries; i++){

		while(curr_right < queries[i].r){
			curr_right++;
			check_right(id[curr_right]);
		} 
		while(curr_right > queries[i].r){
			check_right(id[curr_right]);
			curr_right--;
		}
		while(curr_left < queries[i].l){
			check_left(id[curr_left]);
			curr_left++;
		}
		while(curr_left > queries[i].l){
			curr_left--;
			check_left(id[curr_left]);
		}

		ans[queries[i].idx] = get_answer(queries[i].lca);
	}

	for(int i = 0; i < num_queries; i++){
		cout << ans[i] << "\n";
	}

	return 0;
}