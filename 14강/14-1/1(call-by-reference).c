#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Square(int* par) {
    int result;
    result = (*par) * (*par);
    printf("%d", result);
}

int main(void) {
    int num;
    printf("ÀÔ·Â°ª : ");
    scanf("%d", &num);
    Square(&num);
    return 0;
}