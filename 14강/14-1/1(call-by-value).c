#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Square(int num) {
    int result;
    result = num * num;
    return result;
}

int main(void) {
    int num;
    printf("ÀÔ·Â°ª : ");
    scanf("%d", &num);
    printf("%d", Square(num));
    return 0;
}