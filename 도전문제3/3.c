#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i;
    int div=RAND_MAX/330;
    printf("난수의 범위 : 0부터 %d까지 \n", div);
    for(i=0; i<5; i++){
        printf("난수 출력 : %d \n", rand()%div );
    }
    return 0;
}