#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int arr1[2][4] = { 1,2,3,4,5,6,7,8 };
    int arr2[4][2];
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            int result = arr2[i][j] = arr1[j][i];
            printf("%d", arr2[i][j]);
        }
        printf("\n");
    }
    return 0;
}