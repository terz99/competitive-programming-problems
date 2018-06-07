#include <bits/stdc++.h>
using namespace std;

class Solution {

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() == 0 && nums2.size() == 0){
            return 0;
        }

        if(nums2.size() == 0){
            if(nums1.size() & 1){
                return nums1[nums1.size()/2];
            } else {
                return avg(nums1[nums1.size()/2], nums1[nums1.size()/2 - 1]);
            }
        }
        if(nums1.size() == 0){
            if(nums2.size() & 1){
                return nums2[nums2.size()/2];
            } else {
                return avg(nums2[nums2.size()/2], nums2[nums2.size()/2 - 1]);
            }
        }

        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();

        int low = 0;
        int high = x;

        double res;
        while(low <= high){

            int posX = (low+high)/2;
            int posY = (x+y+1)/2 - posX;

            int maxLeftX = (posX == 0) ? INT_MIN : nums1[posX-1];
            int minRightX = (posX == x) ? INT_MAX : nums1[posX];

            int maxLeftY = (posY == 0) ? INT_MIN : nums2[posY-1];
            int minRightY = (posY == y) ? INT_MAX : nums2[posY];

            if(maxLeftX <= minRightY && maxLeftY <= minRightX){

                if((x+y) & 1){
                    res = (double)max(maxLeftX, maxLeftY);
                    break;
                } else {
                    res = avg(max(maxLeftY, maxLeftX), min(minRightX, minRightY));
                    break;
                }
            } else if(maxLeftX > minRightY){
                high = posX - 1;
            } else {
                low = posX + 1;
            }
        }
        return res;
    }

private: 

    double avg(int x, int y){
        return (double)(x+y)/2.0;
    }
};

int main() {

    srand(static_cast<unsigned int>(time(NULL)));
    int n, m;
    cin >> n >> m;
//    n = rand()%11;
//    m = rand()%11;
//    cout << n << " "  << m << endl;
    vector<int> v1(n);
    vector<int> v2(m);
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> v1[i];
//        v1[i] = rand()%100+1;
//        v.push_back(v1[i]);
    }
    for(int i = 0; i < m; i++){
        cin >> v2[i];
//        v2[i] = rand()%100+1;
//        v.push_back(v2[i]);
    }
//    sort(v1.begin(), v1.end());
//    sort(v2.begin(), v2.end());
//    sort(v.begin(), v.end());
//    for(int i = 0; i < n; i++){
//        cout << v1[i] << " ";
//    } cout << endl;
//    for(int i = 0; i < m; i++){
//        cout << v2[i] << " ";
//    } cout << endl;
//    for(int i = 0; i < v.size(); i++){
//        cout << v[i] << " ";
//    } cout << endl;

    Solution sol;
    double res = sol.findMedianSortedArrays(v1, v2);
    cout << res << endl;

    return 0;
}