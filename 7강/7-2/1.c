#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int total=0, input=0, i=0;
	printf("값 5개를 입력하시오! \n");
	while (i < 5) {
		while (input <= 0) {
			printf("0보다 큰수를 입력!(%d번째)", i+1);
			scanf("%d", &input);
		}
		total += input;
		input = 0;
		i++;
	}
	printf("%d \n", total);
	return 0;
}