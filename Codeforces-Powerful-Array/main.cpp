#include <bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"

typedef long long ll;

const int MAX_ELEMS = 200005;
const int MAX_QUERIES = 200005;

struct query{

	int left_idx;
	int right_idx;
	int block;
	int query_idx;

	query(){}

	bool operator<(const query &q){
		if(block == q.block){
			return right_idx < q.right_idx;
		}
		return block < q.block;
	} 
};

int num_elem;
int num_queries;
ll elem[MAX_ELEMS];
ll query_res[MAX_QUERIES];
int block_size = 448;
ll res;
ll vis[1000005];
query queries[MAX_QUERIES];
int curr_left;
int curr_right;

void add(ll curr_elem){

	if(vis[curr_elem] != 0){
		res -= vis[curr_elem]*vis[curr_elem]*curr_elem;
	}
	vis[curr_elem]++;
	res += vis[curr_elem]*vis[curr_elem]*curr_elem;
}

void remove(ll curr_elem){

	res -= vis[curr_elem]*vis[curr_elem]*curr_elem;
	vis[curr_elem]--;
	if(vis[curr_elem] != 0){
		res += vis[curr_elem]*vis[curr_elem]*curr_elem;
	}
}

int main(){

	IO;

	cin >> num_elem;
	cin >> num_queries;

	for(int i = 0; i < num_elem; i++){
		cin >> elem[i];
	}

	for(int i = 0; i < num_queries; i++){

		cin >> queries[i].left_idx;
		cin >> queries[i].right_idx;
		queries[i].left_idx--;
		queries[i].right_idx--;
		queries[i].block = queries[i].left_idx/block_size;
		queries[i].query_idx = i;
	}

	sort(queries, queries + num_queries);

	add(elem[0]);
	for(int i = 0; i < num_queries; i++){

		while(curr_left < queries[i].left_idx){
			remove(elem[curr_left]);
			curr_left++;
		}
		while(curr_left > queries[i].left_idx){
			curr_left--;
			add(elem[curr_left]);
		}
		while(curr_right < queries[i].right_idx){
			curr_right++;
			add(elem[curr_right]);
		}
		while(curr_right > queries[i].right_idx){
			remove(elem[curr_right]);
			curr_right--;
		}
		query_res[queries[i].query_idx] = res;
	}

	for(int i = 0; i < num_queries; i++){
		cout << query_res[i] << endl;
	}

	return 0;
}