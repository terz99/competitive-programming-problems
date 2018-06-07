#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v; 
        v.push_back(0);
        if(num == 0){
            return v;
        }
        v.push_back(1);
        if(num == 1){
            return v;
        }

        int seg = 1;
        int next = 2;
        while((int)v.size() < num+1){
            int currSeg = seg;
            while(currSeg){
                int end = v.size();
                for(int i = end-currSeg; i < end; i++){
                    v.push_back(v[i]);
                    if((int)v.size() == num+1){
                        break;
                    }
                }
                if((int)v.size() == num+1){
                    break;
                }
                currSeg /= 2;
            }
            if((int)v.size() == num+1){
                break;
            }
            v.push_back(next++);
            seg *= 2;
        }
        return v;
    }
};

int main(){

    int num;
    cin >> num;
    Solution sol;
    vector<int> res = sol.countBits(num);
    for(auto el : res){
        cout << el << " " << endl;
    }
    cout << endl;

    return 0;
}