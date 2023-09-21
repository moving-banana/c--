#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int total = 0;
	int num = 1;

	while (num!=0) {
		scanf("%d", &num);
		printf("입력값 : %d", num);
		total += num;
	}

	printf("입력값의 합 : %d \n", total);
	return 0;
}