#include <bits/stdc++.h>
using namespace std;

int maxPoints(int X[], int Y[],int N) {

    if(N <= 2){
        return N;
    }

    map< pair<int, int>, int> slopeCnt;
    int res, currMax, verticalPoints, overLaps;
    res = 0;

    for(int i = 0; i < N; i++){

        currMax = verticalPoints = overLaps = 0;

        for(int j = i+1; j < N; j++){

            if(X[i] == X[j] && Y[i] == Y[j]){
                overLaps++;
            } else if(X[i] == X[j]){
                verticalPoints++;
            } else {

                int xDiff = X[j] - X[i];
                int yDiff = Y[j] - Y[i];
                int g = __gcd(xDiff, yDiff);

                xDiff /= g;
                yDiff /= g;

                slopeCnt[{xDiff, yDiff}]++;
                currMax = max(currMax, slopeCnt[{xDiff, yDiff}]);
            }

            currMax = max(currMax, verticalPoints);
        } 

        res = max(res, currMax + overLaps + 1);
        slopeCnt.clear();
    }

    return res;
}

int main(){

    return 0;
}