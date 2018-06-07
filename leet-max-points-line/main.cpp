#include <bits/stdc++.h>
using namespace std;


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 
class Solution {

public:
    int maxPoints(vector<Point>& points) {

        int n = points.size();
        if(n < 2){
            return n;
        }

        map< pair<int, int>, int> slopeCnt;
        int res, verticalPoints, overLap, currMax;
        res = currMax = 0;

        for(int i = 1; i < n; i++){

            currMax = verticalPoints = overLap = 0;
            for(int j = 0; j < i; j++){

                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    overLap++;
                } else if(points[i].x == points[j].x){
                    verticalPoints++;
                } else {

                    int yDiff = points[j].y - points[i].y;
                    int xDiff = points[j].x - points[i].x;

                    int g = __gcd(xDiff, yDiff);

                    xDiff /= g;
                    yDiff /= g;

                    slopeCnt[{yDiff, xDiff}]++;
                    currMax = max(currMax, slopeCnt[{yDiff, xDiff}]);
                }

                currMax = max(currMax, verticalPoints);
            }

            res = max(res, currMax+overLap+1);

            slopeCnt.clear();
        }

        return res;
    }
};

int main(){

    return 0;
}