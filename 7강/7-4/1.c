#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int input1, input2;
	int total = 0;
	printf("�Է°� 1��° : ");
	scanf("%d", &input1);
	printf("�Է°� 2��° : ");
	scanf("%d", &input2);
	for (total = 0; input1 <= input2; input1++) {
		total += input1;
	}
	printf("������ �� : %d \n", total);
	return 0;
}