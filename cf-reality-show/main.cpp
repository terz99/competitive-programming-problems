#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll curr, m;
ll backup[300005];
map<ll, int> tree;

struct query{
    int t, q;
    bool operator<(const query &q) const{
        return t < q.t;
    }
};

void add(ll x){
    tree[x]++;
}

void rem(ll x){
    tree[x]--;
    if(tree[x] == 0){
        tree.erase(x);
    }
}

bool check(){
    ll tmp;
    if(tree.empty()) tmp = curr;
    else tmp = tree.begin()->first + m;
    return curr >= 0 && tmp >= 0;
}

int main(){

    int a, b, c, d, len, start, n;
    cin >> n >> a >> b >> c >> d >> start >> len;
    query q[n+5];
    vector<int> intervals;
    intervals.push_back(0);
    for(int i = 0; i < n; i++){
        cin >> q[i].t >> q[i].q;
        intervals.push_back(q[i].t);
        intervals.push_back(q[i].t+1);
        if(q[i].t >= len){
            intervals.push_back(q[i].t-len);
        }
        if(q[i].t >= len-1){
            intervals.push_back(q[i].t-len+1);
        }
    }

    sort(intervals.begin(), intervals.end());
    intervals.erase(unique(intervals.begin(), intervals.end()), intervals.end());

    curr = start;
    m = 0;
    ll sum = 0;
    int s = 0, e = 0;
    for(int i = 0; i < (int)intervals.size(); i++){

        while(e < n && intervals[i] + len > q[e].t){
            
            sum += q[e].q ? c : -d;
            backup[e] = curr + sum - m;
            add(backup[e]);
            e++;
        }
        while(s < n && q[s].t < intervals[i]){

            rem(backup[s]);
            curr += q[s].q ? a : -b;
            sum -= q[s].q ? c : -d;
            m += q[s].q ? (a - c) : -(b - d);
            s++;
        }
        if(check()){
            cout << intervals[i] << endl;
            return 0;
        }
        if(curr < 0){
            break;
        }
    }
    cout << -1 << endl;

    return 0;
}