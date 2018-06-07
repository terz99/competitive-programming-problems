#include <iostream>

int main() {

    int cases;
    std::cin >> cases;
    while(cases--){

        int n, m;
        std::cin >> n >> m;

        int mod = n%m;
        if(mod == 0){
            std::cout << n << std::endl;
        } else {

            if(mod < 0){

                if(abs(mod) < abs(m) - abs(mod)){
                    std::cout << n - mod << std::endl;
                } else {
                    std::cout << n - abs(m) - mod << std::endl;
                }
            } else {

                if(mod < m - mod){
                    std::cout << n - mod << std::endl;
                } else {
                    std::cout << n + m - mod << std::endl;
                }
            }
        }
    }

    return 0;
}