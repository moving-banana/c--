#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct employee {
	char name[20];
	char number[20];
	int pay;
};

int main(void) {
	struct employee worker;
	printf("이름 입력 : ");
	scanf("%s", worker.name);
	printf("주민번호 입력 : ");
	scanf("%s", worker.number);
	printf("연봉 입력 : ");
	scanf("%d", &worker.pay);

	printf("연봉은? : %d", worker.pay);
	return 0;
}