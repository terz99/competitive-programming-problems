#include <bits/stdc++.h>
using namespace std;

int solve(const int a[], int n){

    int topVal;
    int currArea;
    int maxArea = 0;
    int i = 0;
    stack<int> s;

    while(i < n){

        if(s.empty() || a[s.top()] <= a[i]) {
            s.push(i++);
        } else {

            topVal = a[s.top()];
            s.pop();
            currArea = topVal*i;

            if(!s.empty()){
                currArea = topVal*(i-s.top()-1);
            }
            maxArea = max(maxArea, currArea);
        }
    }

    while(!s.empty()){

        topVal = a[s.top()];
        s.pop();
        currArea = topVal*i;

        if(!s.empty()){
            currArea = topVal*(i-s.top()-1);
        }
        maxArea = max(maxArea, currArea);
    }

    return maxArea;
}

int main() {

    int cases;
    cin >> cases;
    while(cases--){

        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        cout << solve(a, n) << endl;
    }

    return 0;
}