#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct employee {
	char name[20];
	char number[20];
	int pay;
};

int main(void) {
	struct employee arr[3];
	int i;
	for (i = 0; i < 3; i++) {
		printf("%d번째 직원 정보 입력 : \n", i + 1);
		scanf("%s %s %d", arr[i].name, arr[i].number, &arr[i].pay);
	}
	for (i = 0; i < 3; i++) {
		printf("%s %s %d\n", arr[i].name, arr[i].number, arr[i].pay);
	}
	return 0;
}