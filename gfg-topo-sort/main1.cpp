#include <bits/stdc++.h>
using namespace std;

int * topoSort(vector<int> graph[], int N){

    int* res = new int[N];
    vector<int> inDegree(N, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < graph[i].size(); j++){
            int node = graph[i][j];
            inDegree[node]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < N; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    int res_i = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res[res_i++] = curr;
        for(int i = 0; i < graph[curr].size(); i++){
            int next = graph[curr][i];
            if(--inDegree[next] == 0){
                q.push(next);
            }            
        }
    }

    return res;
}

int main(){
    return 0;
}