#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& a) {

        int i = a.size()-2;
        while(i >= 0 && a[i+1] <= a[i]){
            i--;
        }

        if(i >= 0){
            int j = a.size()-1;
            while(j >= 0 && a[j] <= a[i]){
                j--;
            }
            swap(a[i], a[j]);
        }

        int start = i+1;
        int end = a.size()-1;
        while(start < end){
            swap(a[start], a[end]);
            start++;
            end--;
        }
    }
};

static const auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Solution sol;
    sol.nextPermutation(a);
    for(auto el : a){
        cout << el << " ";
    }
    cout << endl;

    return 0;
}