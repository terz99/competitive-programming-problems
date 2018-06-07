#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> q;
        for(int i = 0; i < (int)nums.size(); i++){

            q.push(-nums[i]);
            if(q.size() > k){
                q.pop();
            }
        }
        return -q.top();
    }
};

int main() {

    srand(static_cast<unsigned int>(time(NULL)));

    int n;
    n = rand()%10 + 1;
    cout << n << endl;
    vector<int> v;
    v.resize(n);
    for(int i = 0; i < n; i++){
        v[i] = rand()%100;
        cout << v[i] << " ";
    }
    int k = rand()%n + 1;
    cout << endl << k << endl;

    Solution sol;
    cout << sol.findKthLargest(v, k) << endl;

    return 0;
}