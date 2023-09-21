#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	for (int i = 0; i < 2; i++)
	{
		int random = (rand() % 6) + 1; // 1 ~ 6 사이의 숫자를 뽑아서 random 변수에 저장
		printf("주사위%d 의 결과 : %d \n", i + 1, random);
	}
	return 0;
}