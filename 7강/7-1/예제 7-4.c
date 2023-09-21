#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int dan = 0, num = 9;
    printf("¸î ´Ü? ");
    scanf("%d", &dan);

    while (num > 0) {
        printf("%d x %d = %d \n", dan, num, dan * num);
        num--;
    }
    return 0;
}