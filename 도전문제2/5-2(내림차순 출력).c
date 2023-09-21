#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void BubbleSort(int ary[], int len);

int main(void) {
    int arr[7];
    int i;
    printf("정수4개 입력 : ");
    scanf("%d %d %d %d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &arr[6]);
    printf("입력한 정수의 기본 배열 : ");
    for (i = 0; i < 7; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");

    BubbleSort(arr, sizeof(arr) / sizeof(int));
    for (i = 0; i < 7; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}

void BubbleSort(int ary[], int len) {
    int i, j;
    int temp;

    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < (len - i) - 1; j++) {
            if (ary[j] < ary[j + 1]) {
                temp = ary[j + 1];
                ary[j + 1] = ary[j];
                ary[j] = temp;
            }
        }
    }
}