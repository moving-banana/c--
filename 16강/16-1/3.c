#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int arr[5][5] = { 5,4,6,5,NULL,3,6,9,3,NULL,4,8,2,7,NULL,3,8,9,7,NULL };
    int i, j;
    int result = 0;
    int resultArr1[4];
    int resultArr2[4];
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    //���� ��
    for (i = 0; i < 4; i++) {
        result = 0;
        for (j = 0; j < 4; j++) {
            result += arr[i][j];
            resultArr1[i] = result;
        }
        printf(" %d", resultArr1[i]);
    }
    printf("\n");
    printf("������ �� : ");
    for (i = 0; i < 3; i++) {
        result += resultArr1[i];
    }
    printf("%d\n", result);
    //���� ��
    for (i = 0; i < 4; i++) {
        result = 0;
        for (j = 0; j < 4; j++) {
            result += arr[j][i];
            resultArr2[i] = result;
        }
        printf(" %d", resultArr2[i]);
    }
    printf("\n");
    printf("������ �� : ");
    for (i = 0; i < 3; i++) {
        result += resultArr2[i];
    }
    printf("%d\n", result);
    //���� ������ ��
    arr[4][4] = result;
    //�迭�ϱ�
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            arr[i][4] = resultArr2[i];
            arr[4][i] = resultArr1[i];
        }
    }
    //�������
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            arr[4][4] = result;
            printf("%-4d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}