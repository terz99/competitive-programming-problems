#include <bits/stdc++.h>
using namespace std;

void topoSort(int curr, vector<int> graph[], stack<int>& s, bool vis[]){

    vis[curr] = true;
    for(int i = 0; i < graph[curr].size(); i++){
        int next = graph[curr][i];
        if(!vis[next]){
            topoSort(next, graph, s, vis);
        }
    }

    s.push(curr);
}

int * topoSort(vector<int> graph[], int N){

    bool vis[N];
    memset(vis, false, sizeof(vis));

    stack<int> s;

    for(int i = 0; i < N; i++){
        if(!vis[i]){
            topoSort(i, graph, s, vis);
        }
    }

    int* res = new int[N];

    for(int i = 0; i < N; i++){
        res[i] = s.top();
        s.pop();
    }    

    return res;
}

int main(){
    return 0;
}