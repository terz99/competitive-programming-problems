#include <bits/stdc++.h>
using namespace std;

struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution{

public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
        
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }

        int leftIdx = -1;
        int rightIdx;
        int leftVal = newInterval.start;
        int rightVal = newInterval.end;

        for(int i = 0; i < intervals.size(); i++){

            if(i != 0 && intervals[i-1].end < newInterval.start && intervals[i].start > newInterval.end){
                intervals.insert(intervals.begin()+i, newInterval);
                return intervals;
            } else if(intervals[i].end < newInterval.start || intervals[i].start > newInterval.end){
                continue;
            } else {
                if(leftIdx == -1){
                    leftIdx = i;
                }
                leftVal = min(leftVal, intervals[i].start);
                rightVal = max(rightVal, intervals[i].end);
                rightIdx = i;
                cout << "leftIdx: " << leftIdx << endl;
                cout << "rightIdx: " << rightIdx << endl;
                cout << "leftVal: " << leftVal << endl;
                cout << "rightVal: " << rightVal << endl;
            }
        }

        if(leftIdx == -1){
            if(newInterval.end < intervals[0].start){
                intervals.insert(intervals.begin(), newInterval);
            } else {
                intervals.push_back(newInterval);
            }
        } else {
            intervals[leftIdx].start = leftVal;
            intervals[leftIdx].end = rightVal;
            intervals.erase(intervals.begin()+leftIdx+1, intervals.begin()+rightIdx+1);
        }
        return intervals;
    }
};

int main(){

    return 0;
}