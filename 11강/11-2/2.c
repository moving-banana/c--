#include <stdio.h>

int main(void){
    char str[100];
    int len=0;

    printf("�Է°� : ");
    scanf("%s", str);

    while(str[len] !=0){
        len++;
    }
    printf("���̴� : %d \n", len);
    return 0;
}