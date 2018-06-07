#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites) {
        
        int adj[numCourses][numCourses];
        int inDegree[numCourses];

        memset(inDegree, 0, sizeof(inDegree));
        memset(adj, 0, sizeof(adj));

        for(int i = 0; i < prerequisites.size(); i++){
            
            int to = prerequisites[i].first;
            int from = prerequisites[i].second;
            if(adj[from][to] == 0){
                inDegree[to]++;
            }
            adj[from][to] = 1;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cnt++;
            for(int i = 0; i < numCourses; i++){
                if(adj[curr][i]){
                    if(--inDegree[i] == 0){
                        q.push(i);
                    }
                }
            }
        }

        return cnt == numCourses;
    }
};

int main(){
    return 0;
}