#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int total = 0;
	int num = 1;

	while (num!=0) {
		scanf("%d", &num);
		printf("�Է°� : %d", num);
		total += num;
	}

	printf("�Է°��� �� : %d \n", total);
	return 0;
}