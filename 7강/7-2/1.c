#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int total=0, input=0, i=0;
	printf("�� 5���� �Է��Ͻÿ�! \n");
	while (i < 5) {
		while (input <= 0) {
			printf("0���� ū���� �Է�!(%d��°)", i+1);
			scanf("%d", &input);
		}
		total += input;
		input = 0;
		i++;
	}
	printf("%d \n", total);
	return 0;
}