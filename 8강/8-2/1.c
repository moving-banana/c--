#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int dan, i;
	for (dan = 1; dan < 10; dan++) {
		for (i = 1; i < 10; i++) {
			if (dan % 2 == 0) {
				printf("%d x %d \n", dan, i);
				if (dan == i)
					break;
			}
		}
	}
	return 0;
}