#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num1, num2;
	printf("두 수 입력 : ");
	scanf("%d %d", &num1, &num2);
	int result= num1 > num2 ? num1 - num2 : num2 - num1;
	printf("결과값 : %d", result);
	return 0;
}