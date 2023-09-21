#include <stdio.h>

int ChooseBigger(int num1, int num2) {
	if (num1 > num2) {
		return num1;
	}
	else {
		return num2;
	}
}

int ChooseLower(int num1, int num2) {
	if (num1 > num2) {
		return num2;
	}
	else {
		return num1;
	}
}

int main(void) {
	int num1, num2, i, dan;
	int dan1, dan2;
	printf("?? ??? ??? : ");
	scanf("%d %d", &num1, &num2);
	printf("%d?? ~ %d?? \n", dan1=ChooseLower(num1, num2), dan2=ChooseBigger(num1, num2));
	for (dan = dan1; dan < (dan2+1); dan++) {
		for (i = 1; i < 10; i++) {
			printf("%d x %d = %d \n", dan, i, dan * i);
		}
	}
	return 0;
}

