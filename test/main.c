#include <stdio.h>
// #define DEBUG

int main(){

    int data[10];
    int sqr[10];
    for(int i = 0; i < 10; i++){
        data[i] = i;
        sqr[i] = i*i;
        #ifdef DEBUG
            printf("%d", data[i]);
        #endif
    }

    return 0;
}