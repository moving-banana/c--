#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int i = 0;
	int total = 0;
	do{
		total += i;
		i = i * 2;
	} while (i<=100);

	printf("Â¦¼ö°ªÀÇ ÇÕ : %d \n", total);
	return 0;
}