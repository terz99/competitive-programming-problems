#include <bits/stdc++.h>
using namespace std;

class Solution {

    class State{
    public:
        int numSteps;
        string str;
        State *state;
        State(){
            numSteps = 0;
            str = "";
            state = NULL;
        }
        State(const string& str, const int& numSteps, State* state){
            this->str = str;
            this->numSteps = numSteps;
            this->state = state;
        }
    };

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        set<string> words;
        for(int i = 0; i < wordList.size(); i++){
            words.insert(wordList[i]);
        }
        vector< vector<string> > res;
        if(words.empty() || words.find(endWord) == words.end()){
            return res;
        }

        queue<State*> q;
        q.push( new State(beginWord, 1, new State()) );
        int minSteps = 0;
        int preNumSteps = 0;
        set<string> visited;

        while(!q.empty()){

            State* preState = q.front();
            int currNumSteps = q.front()->numSteps;
            string curr = q.front()->str;
//            cout << curr << " " << currNumSteps << endl;
            q.pop();

            if(curr == endWord){

                if(minSteps == 0){
                    minSteps = currNumSteps;
                }

                if(minSteps == currNumSteps && minSteps != 0){

//                    cout << currNumSteps << endl;
                    vector<string> tmp;
                    while(preState->state != NULL) {
//                        cout << preState->str << endl;
                        tmp.push_back(preState->str);
                        preState = preState->state;
                    }
                    reverse(tmp.begin(), tmp.end());
                    res.push_back(tmp);
                }
                continue;
            }

            if(preNumSteps < currNumSteps){
                for(set<string>::iterator it = visited.begin(); it != visited.end(); it++){
                    words.erase(*it);
                }
                visited.clear();
            }

            preNumSteps = currNumSteps;
            for(int i = 0; i < curr.length(); i++){
                for(char c = 'a'; c <= 'z'; c++){

                    char tmp = curr[i];
                    if(curr[i] != c){

                        curr[i] = c;
                        if(words.find(curr) != words.end()){
                            q.push( new State(curr, currNumSteps+1, preState) );
                            visited.insert(curr);
                        }
                    }
                    curr[i] = tmp;
                }
            }
        }
        return res;
    }
};

int main() {

    int n;
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    cin >> n;
    vector<string> wordList;
    wordList.resize(n);
    for(int i = 0; i < n; i++){
        cin >> wordList[i];
    }

    Solution sol;
    vector< vector<string> > res = sol.findLadders(beginWord, endWord, wordList);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        } cout << endl;
    }

    return 0;
}