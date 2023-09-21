#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int arr1[3], arr2[3];
    printf("START GAME!!\n");
    int i, j, k;
    srand(time(NULL));
    for (j = 0; j < 3; j++) {
        arr2[j] = rand() % 9; // 1 ~ 3 사이의 숫자를 뽑아서 random 변수에 저장
    }
    for (k = 0; k < 100; k++) {
        int strike = 0, ball = 0;
        printf("3개의 숫자 선택 : ");
        scanf("%d %d %d", &arr1[0], &arr1[1], &arr1[2]);
        for (j = 0; j < 3; j++) {  // 난수 출력
            printf("%d\n", arr2[j]);
        }
        for (i = 0; i < 3; i++) {
            if (arr1[i] == arr2[i]) {
                strike++;
            }
            for (j = 0; j < 3; j++) {
                if (arr1[i] == arr2[j]) {
                    ball++;
                }
            }
        }
        ball -= strike;
        printf("%d번째 도전 결과 : %d strike %d ball\n", k + 1, strike, ball);
        if (strike == 3)
            break;
    }
    printf("승리! (%d)회만에 성공!\n", k + 1);
    return 0;
}