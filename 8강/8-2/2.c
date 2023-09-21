#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int num1,num2;
	for (num1 = 1; num1 < 9; num1++) {
		for (num2 = 1; num2 < 9; num2++) {
			if (10 * num1 + num2 + 10 * num2 + num1 != 99)
				continue;
			else if (10 * num1 + num2 + 10 * num2 + num1 == 99)
				break;
		}
		printf("%d , %d \n", num1, num2);
	}
	return 0;
}