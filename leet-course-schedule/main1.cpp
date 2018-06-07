#include <bits/stdc++.h>
using namespace std;

class Solution {

    void topoSort(const int& curr, vector<bool>& vis, const vector< vector<bool> >& adj, stack<int>& s){

        vis[curr] = true;

        for(int i = 0; i < adj[curr].size(); i++){
            int next = adj[curr][i];
            if(!vis[next]){
                topoSort(next, vis, adj, s);
            }
        }

        s.push(curr);
    }

public:
    bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites) {
        
        vector< vector<bool> > adj(numCourses, vector<bool>(numCourses, false));

        for(int i = 0; i < prerequisites.size(); i++){
            int to = prerequisites[i].first;
            int from = prerequisites[i].second;
            adj[from][to] = true;
        }

        stack<int> s;
        vector<bool> vis(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!vis[i]){
                topoSort(i, vis, adj, s);
            }
        }

        int cnt = 0;
        while(!s.empty()){
            cnt++;
            s.pop();
        }

        return cnt == numCourses;
    }
};

int main(){
    return 0;
}