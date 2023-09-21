#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num;
    int arr[100];
    int i = 0;
    printf("10진수 입력 : ");
    scanf("%d", &num);
    while (num > 0) {
        arr[i] = num % 2;
        num /= 2;
        i++;
    }
    for (int z = i - 1; z >= 0; z--) {
        printf("%d", arr[z]);
    }
    return 0;
}