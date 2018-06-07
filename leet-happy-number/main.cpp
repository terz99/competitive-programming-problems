class Solution {
public:
    bool isHappy(int n) {
        
        int cnt = 0;
        while(cnt < 100000 && n != 1){
            
            cnt++;
            int tmp = 0;
            while(n > 0){
                tmp += (n%10)*(n%10);
                n /= 10;
            }
            n = tmp;
        }
        return n == 1;
    }
};