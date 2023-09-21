#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int s1, s2, s3;
	double total = 0;
	printf("점수를 입력 \n");
	printf("국어 : \n");
	scanf("%d", &s1);
	printf("수학 : \n");
	scanf("%d", &s2);
	printf("과학 : \n");
	scanf("%d", &s3);
	total = (s1 + s2 + s3)/3.0;
	printf("평균 점수는 : %f \n", total);
	if (total >= 80.0) {
		printf("점수는 A \n");
	}
	else if (total >= 70.0) {
		printf("점수는 B \n");
	}
	else if (total >= 60.0) {
		printf("점수는 C \n");
	}
	else {
		printf("점수는 F \n");
	}
	return 0;
}