#include <bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

typedef long long ll;

const int MAX = 30005;
const int MAX_QUERIES = 200005;
const int MAX_NUM = 1000005;

struct query{

	int left_idx;
	int right_idx;
	int block;
	int query_idx;
	query(){}

	bool operator<(const query &q)const{
		if(block == q.block){
			return right_idx < q.right_idx;
		} else {
			return block < q.block;
		}
	}
};	

query queries[MAX_QUERIES];
int len;
int num_queries;
int block_size = 174;
int arr[MAX];
int res = 0;
int query_results[MAX_QUERIES];
int vis[MAX_NUM];

void add(int elem){
	if(vis[elem] == 0){
		res++;
	}
	vis[elem]++;
}

void remove(int elem){
	vis[elem]--;
	if(vis[elem] == 0){
		res--;
	}
}

int main(){

	IO;


	cin >> len;
	for(int i = 0; i < len; i++){
		cin >> arr[i];
	}

	cin >> num_queries;
	for(int i = 0; i < num_queries; i++){
		cin >> queries[i].left_idx; 
		cin >> queries[i].right_idx;
		queries[i].left_idx--;
		queries[i].right_idx--;
		queries[i].block = queries[i].left_idx / block_size;
		queries[i].query_idx = i;
	}

	sort(queries, queries + num_queries);

	int curr_left = 0;
	int curr_right = 0;
	add(arr[0]);
	for(int i = 0; i < num_queries; i++){

		while(curr_left < queries[i].left_idx){
			remove(arr[curr_left]);
			curr_left++;
		}
		while(curr_left > queries[i].left_idx){
			curr_left--;
			add(arr[curr_left]);
		}
		while(curr_right < queries[i].right_idx){
			curr_right++;
			add(arr[curr_right]);
		}
		while(curr_right > queries[i].right_idx){
			remove(arr[curr_right]);
			curr_right--;
		}
		query_results[queries[i].query_idx] = res;
	}

	for(int i = 0; i < num_queries; i++){
		cout << query_results[i] << endl;
	}

	return 0;
}