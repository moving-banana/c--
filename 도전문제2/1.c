#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void EvenNum(int* par) {
    int i;
    printf("짝수 : ");
    for (i = 0; i < 10; i++) {
        if ((par[i]) % 2 == 0) {
            printf(" %d", par[i]);
        }
    }
}

void OddNum(int* par) {
    int i;
    printf("홀수 : ");
    for (i = 0; i < 10; i++) {
        if ((par[i]) % 2 != 0) {
            printf(" %d", par[i]);
        }
    }
}
int main(void) {
    printf("총 10개의 정수 입력\n");
    int num;
    int arr[10];
    int i;
    for (i = 0; i < 10; i++) {
        printf("입력 %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("입력된 배열 : ");
    for (i = 0; i < 10; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    EvenNum(&arr);
    printf("\n");
    OddNum(&arr);
    return 0;
}