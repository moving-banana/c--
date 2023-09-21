#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 6

int main() {

	int rotto[SIZE];
	int i, j;

	srand((unsigned)time(NULL));

	for (i = 0; i < SIZE; i++) {	// 로또번호 뽑기
		rotto[i] = (rand() % 45) + 1; //1부터 45까지 난수 생성
		for (j = 0; j < i; j++) {
			if (rotto[i] == rotto[j]) i--; //번호 중복시 i값을 감소시켜서 다시 진행
		}
	}

	printf("로또번호 생성기: \n");	// 출력
	for (i = 0; i < SIZE; i++) {
		printf("%d ", rotto[i]);
	}

	return 0;
}