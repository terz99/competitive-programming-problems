#include <iostream>

int choose(int n, int i){

    int num = 1;
    for(int j = n; j > n-i; j--){
        num *= j;
    }
    if(i == 0) i = 1;
    int den = 1;
    for(int j = 1; j <= i; j++){
        den *= j;
    }
    return num/den;
}

int main(){

    int cases;
    std::cin >> cases;
    while(cases--){

        int n;
        std::cin >> n;
        if(n == 1){
            std::cout << 3 << std::endl;
        } else {

            int res = 0;
            for(int i = 0; i <= 1; i++){
                for(int j = 0; j <= std::min(n-i, 2); j++){
                    res += choose(n, i)*choose(n-i, j);
                }
            }
            std::cout << res << std::endl;
        }
    }

    return 0;
}