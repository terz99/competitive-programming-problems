#include <bits/stdc++.h>
using namespace std;

class RangeModule {

    class Interval{
        public:
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(const int& start, const int& end){
            this->start = start;
            this->end = end;
        } 
    };

    vector<Interval> intervals;

public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {

        vector<Interval> ret;
        auto it = intervals.begin();
        for(; it != intervals.end(); it++){
            if(right < (*it).start){
                break;
            } else if(left > (*it).end){
                ret.push_back(*it);
            } else {
                left = min(left, (*it).start);
                right = max(right, (*it).end);
            }
        }
        ret.push_back(Interval(left, right));
        for(; it != intervals.end(); it++){
            ret.push_back(*it);
        }
        intervals = ret;
    }
    
    bool queryRange(int left, int right) {
        for(auto interval : intervals){
            if(interval.start <= left && interval.end >= right){
                return true;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        
        vector<Interval> ret;
        auto it = intervals.begin();
        for(; it != intervals.end(); it++){
            if(right < (*it).start){
                break;
            } else if(left > (*it).end){
                ret.push_back(*it);
            } else {
                if((*it).start < left){
                    ret.push_back(Interval((*it).start, left));
                }
                if((*it).end > right){
                    ret.push_back(Interval(right, (*it).end));
                }
            }
        }

        for(; it != intervals.end(); it++){
            ret.push_back(*it);
        }
        intervals = ret;
    }

    void print(){
        cout << "[";
        for(auto interval : intervals){
            cout << "[" << interval.start << ", " << interval.end << "], ";
        }
        cout << "]\n";
    }
};

int main(){

    RangeModule obj;
    while(true){

        char op;
        cin >> op;
        if(op == 'q'){
            break;
        } else if(op == 'a'){
            int a, b;
            cin >> a >> b;
            obj.addRange(a, b);
            obj.print();
        } else if(op == 'b'){
            int a, b;
            cin >> a >> b;
            cout << obj.queryRange(a, b) << endl;
        } else if(op == 'c'){
            int a, b;
            cin >> a >> b;
            obj.removeRange(a, b);
            obj.print();
        }
    }

    return 0;
}

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */