#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int s1, s2, s3;
	double total = 0;
	printf("������ �Է� \n");
	printf("���� : \n");
	scanf("%d", &s1);
	printf("���� : \n");
	scanf("%d", &s2);
	printf("���� : \n");
	scanf("%d", &s3);
	total = (s1 + s2 + s3)/3.0;
	printf("��� ������ : %f \n", total);
	if (total >= 80.0) {
		printf("������ A \n");
	}
	else if (total >= 70.0) {
		printf("������ B \n");
	}
	else if (total >= 60.0) {
		printf("������ C \n");
	}
	else {
		printf("������ F \n");
	}
	return 0;
}