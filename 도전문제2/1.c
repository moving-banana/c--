#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void EvenNum(int* par) {
    int i;
    printf("¦�� : ");
    for (i = 0; i < 10; i++) {
        if ((par[i]) % 2 == 0) {
            printf(" %d", par[i]);
        }
    }
}

void OddNum(int* par) {
    int i;
    printf("Ȧ�� : ");
    for (i = 0; i < 10; i++) {
        if ((par[i]) % 2 != 0) {
            printf(" %d", par[i]);
        }
    }
}
int main(void) {
    printf("�� 10���� ���� �Է�\n");
    int num;
    int arr[10];
    int i;
    for (i = 0; i < 10; i++) {
        printf("�Է� %d : ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("�Էµ� �迭 : ");
    for (i = 0; i < 10; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    EvenNum(&arr);
    printf("\n");
    OddNum(&arr);
    return 0;
}