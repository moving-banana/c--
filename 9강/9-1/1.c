#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int CallBigger(int num1, int num2, int num3);
int CallSmaller(int num1, int num2, int num3);

int main(void) {
	int num1, num2, num3;
	printf("������ ���� �Է� : ");
	scanf("%d %d %d", &num1, &num2, &num3);
	printf("�� �߿��� ���� ū �� : %d \n", CallBigger(num1,num2,num3));
	printf("�� �߿��� ���� ���� �� : %d \n", CallSmaller(num1,num2,num3));
	return 0;
}

int CallBigger(int num1, int num2, int num3) {
	if (num1 > num2 >= num3) {
		return num1;
	}
	else if (num2 > num1 >= num3) {
		return num2;
	}
	else{
		return num3;
	}
}

int CallSmaller(int num1, int num2, int num3) {
	if (num1 < num2 <= num3) {
		return num1;
	}
	else if (num2 < num1 <= num3) {
		return num2;
	}
	else{
		return num3;
	}
}
