#include <stdio.h>

int main(void){
    char str[100];
    int len=0;

    printf("입력값 : ");
    scanf("%s", str);

    while(str[len] !=0){
        len++;
    }
    printf("길이는 : %d \n", len);
    return 0;
}