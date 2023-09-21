#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int i, j;
    int arr[3][9];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 9; j++) {
            int result = arr[i][j] = (i + 2) * (j + 1);
            printf(" %d", result);
        }
        printf("\n");
    }

    return 0;
}