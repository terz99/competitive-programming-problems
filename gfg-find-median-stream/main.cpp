#include <iostream>
#include <queue>
using namespace std;


int main(){

    int n;
    cin >> n;
    priority_queue<int> l, r;
    int effective_median = -1;
    while(n--){

        int next;
        cin >> next;
        int res;
        if(effective_median == -1){
            effective_median = next;
            res = effective_median;
        } else {
            
            if(next < effective_median){
                l.push(next);
            } else {
                r.push(-next);
            }

            if(abs((int)l.size() - (int)r.size()) >= 2){

                if(l.size() > r.size()){

                    int tmp = effective_median;
                    effective_median = l.top();
                    l.pop();
                    r.push(-tmp);
                } else {

                    int tmp = effective_median;
                    effective_median = -r.top();
                    r.pop();
                    l.push(tmp);
                }
                res = effective_median;
            } else {

                if(l.size() > r.size()){
                    res = (effective_median + l.top())/2;
                } else if(l.size() < r.size()){
                    res = (effective_median - r.top())/2;
                } else {
                    res = effective_median;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
