#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void BubbleSort(int any[], int len);

int main(void) {
    int arr[4];
    int i;
    printf("정수4개 입력 : ");
    scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
    printf("입력한 정수의 기본 배열 : ");
    for (i = 0; i < 4; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    BubbleSort(arr, sizeof(arr) / sizeof(int));
    for (i = 0; i < 4; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    return 0;
}

void BubbleSort(int any[], int len) {
    int i, j;
    int temp;

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < (len - i) - 1; j++) {
            if (any[j] > any[j + 1]) {
                temp = any[j];
                any[j] = any[j + 1];
                any[j + 1] = temp;
            }
        }
    }
}