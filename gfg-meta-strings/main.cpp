#include <iostream>
#include <vector>

int main(){

    int cases;
    std::cin >> cases;
    while(cases--){
        
        std::vector<int> idx;
        std::string a, b;
        std::cin >> a >> b;
        if(a == b || a.length() != b.length()){
            std::cout << 0 << std::endl;
        } else {
            for(int i = 0; i < (int)a.length(); i++){
                if(a[i] != b[i]){
                    idx.push_back(i);
                }
            }
            if(idx.size() != 2){
                std::cout << 0 << std::endl;
            } else {

                int i = idx[0];
                int j = idx[1];
                if(a[i] == b[j] && a[j] == b[i]){
                    std::cout << 1 << std::endl;
                } else {
                    std::cout << 0 << std::endl;
                }
            }
        }
    }

    return 0;
}