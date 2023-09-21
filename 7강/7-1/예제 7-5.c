#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num;
    int input;
    int total = 0;
    int i = 0;
    printf("정수 몇개 입력할거임?");
    scanf("%d", &num);
    printf(" %d개요~ \n", num);
    while (i++ < num) {
        printf("입력값: ");
        scanf("%d", &input);
        total+= input;
    }
    printf("다 더한값은 : %d \n", total);
    printf("평균값은 : %f \n", (double)total / num);
    return 0;
}