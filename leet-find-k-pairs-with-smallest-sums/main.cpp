#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool check(vector<int>& a, vector<int>& b, int k, int mid){

        int res = 0;
        for(int i = 0; i < (int)a.size(); i++){
            res += upper_bound(b.begin(), b.end(), mid-a[i]) - b.begin();
        }
        return res >= k;
    }

    class Pair{
        public:
        int x, y, val;
        const bool operator<(const Pair& p) const{
            if(val == p.val){
                if(x == p.x){
                    return y < p.y;
                }
                return x < p.x;
            }
            return val < p.val;
        }
        Pair(int x, int y, int val){
            this->x = x;
            this->y = y;
            this->val = val;
        }
    };

public:
    vector< pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();
        int m = nums2.size();

        if(n == 0 || m == 0){
            return vector< pair<int, int> >();
        }

        // int l = nums1[0] + nums2[0];
        // int r = nums1[n-1] + nums2[m-1];
        // int res = r;

        // while(l <= r){

        //     int mid = (l+r)/2;
        //     if(check(nums1, nums2, k, mid)){
        //         res = mid;
        //         r = mid-1;
        //     } else {
        //         l = mid+1;
        //     }
        // }

        // vector< pair<int, int> > v;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < m; j++){
        //         if(nums1[i]+nums2[j] <= res){
        //             v.push_back( {nums1[i], nums2[j]} );
        //         } else {
        //             break;
        //         }
        //     }
        // }

        // return v;  
        priority_queue<Pair> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                q.push(Pair(nums1[i], nums2[j], -(nums1[i]+nums2[j])));
            }
        }

        vector< pair<int, int> > res;
        while(k > 0){
            k--;
            Pair curr = q.top();
            res.push_back( {curr.x, curr.y} );
        }   
        return res;
    }
};

int main(){ 

    return 0;
}