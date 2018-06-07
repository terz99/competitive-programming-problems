#include <bits/stdc++.h>
using namespace std;

#define IO ios_base::sync_with_stdio(false)
#define endl "\n"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(wordList.size() == 0 || beginWord == endWord){
            return 0;
        }

        wordList.push_back(beginWord);
        int n = (int)wordList.size();
        vector<int> adj[n];
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){

                int cnt = 0;
                for(int k = 0; k < (int)wordList[i].length(); k++){
                    cnt += (wordList[i][k] != wordList[j][k]);
                }
                if(cnt == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int s = n-1;
        int e = -1;
        for(int i = 0; i < n; i++){
            if(wordList[i] == endWord){
                e = i;
                break;
            }
        }
        if(e == -1){
            return 0;
        }

        queue<int> q;
        int vis[n];
        memset(vis, 0, sizeof(vis));
        vis[s] = 1;
        q.push(s);
        while(!q.empty()){

            int curr = q.front();
            q.pop();

            for(int i = 0; i < (int)adj[curr].size(); i++){
                int next = adj[curr][i];
                if(vis[next] == 0){
                    vis[next] = vis[curr] + 1;
                    q.push(next);
                }
            }
        }
        return vis[e];
    }
};

int main(){

    IO;

    string beginWord, endWord;
    vector<string> wordList;
    int n;
    cin >> beginWord >> endWord;
    cin >> n;
    wordList.resize(n);
    for(int i = 0; i < n; i++){
        cin >> wordList[i];
    }

    Solution sol;
    int res = sol.ladderLength(beginWord, endWord, wordList);
    cout << res << endl;

    return 0;
}
