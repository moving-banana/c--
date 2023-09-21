#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int user, i;
    int w = 0, l = 0, d = 0;
    srand(time(NULL));
    for (i = 0; i < 3; i++) {
        printf("1,2,3중 하나 입력(1은 가위,2는 바위,3은 보)");
        scanf("%d", &user);
        int comp = (rand() % 3) + 1; // 1 ~ 3 사이의 숫자를 뽑아서 random 변수에 저장
        if (user == 1) {
            if (comp == 1) {
                printf("당신 : %d , 컴퓨터 : %d \n", user, comp);
                printf("무승부!!\n");
                d++;
            }
            else if (comp == 2) {
                printf("당신 : %d , 컴퓨터 : %d \n", user, comp);
                printf("패배!!\n");
                l++;
            }
            else {
                printf("당신 : %d , 컴퓨터 : %d \n", user, comp);
                printf("승리!!\n");
                w++;
            }
        }
        else if (user == 2) {
            if (comp == 1) {
                printf("당신 : %d , 컴퓨터 : %d \n", user, comp);
                printf("승리!!\n");
                w++;
            }
            else if (comp == 2) {
                printf("당신 : %d , 컴퓨터 : %d \n", user, comp);
                printf("무승부!!\n");
                d++;
            }
            else {
                printf("당신 : %d , 컴퓨터 : %d \n", user, comp);
                printf("패배!!\n");
                l++;
            }
        }
        else {
            if (comp == 1) {
                printf("당신 : %d , 컴퓨터 : %d \n", user, comp);
                printf("패배!!\n");
                l++;
            }
            else if (comp == 2) {
                printf("당신 : %d , 컴퓨터 : %d \n", user, comp);
                printf("승리!!\n");
                w++;
            }
            else {
                printf("당신 : %d , 컴퓨터 : %d \n", user, comp);
                printf("무승부!!\n");
                d++;
            }
        }
    }
    printf("게임의 결과 : %d승 %d무 %d패 \n", w, d, l);
    return 0;
}