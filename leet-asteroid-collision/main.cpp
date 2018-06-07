#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> res;
        if(asteroids.size() == 0){
            return res;
        }

        stack<int> s;

        unsigned int i = 0;
        while(i < asteroids.size()){

            if(s.empty()){
                s.push(asteroids[i++]);
                continue;
            }

            int RIGHT = s.top();
            if(RIGHT < 0){
                s.push(asteroids[i++]);
                continue;
            }

            if(asteroids[i] > 0){
                s.push(asteroids[i++]);
                continue;
            }

            s.pop();
            int LEFT = asteroids[i];
            if(abs(RIGHT) > abs(LEFT)){
                s.push(RIGHT);
                i++;
            } else if(abs(RIGHT) == abs(LEFT)){
                i++;
            }
        }

        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    Solution sol;
    vector<int> res = sol.asteroidCollision(v);
    for(unsigned int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}