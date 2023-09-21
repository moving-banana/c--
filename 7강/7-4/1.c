#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int input1, input2;
	int total = 0;
	printf("입력값 1번째 : ");
	scanf("%d", &input1);
	printf("입력값 2번째 : ");
	scanf("%d", &input2);
	for (total = 0; input1 <= input2; input1++) {
		total += input1;
	}
	printf("값들의 합 : %d \n", total);
	return 0;
}