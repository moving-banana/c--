#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CalToSP(char n[]) { //공백까지의 거리 계산
	int i = 0;
	for (i = 0; i < strlen(n); i++) {
		if (n[i] == 32) {
			return i;
		}
	}
	return -1;
}

int  CompName(char str1[], char str2[]) {
	int idx1 = CalToSP(str1);
	int idx2 = CalToSP(str2);

	if (idx1 != idx2) {
		return 0;
	}
	else {
		return !strncmp(str1, str2, idx1);
	}
}

int CompAge(char str1[], char str2[]) {
	int idx1 = CalToSP(str1);
	int idx2 = CalToSP(str2);
	int age1, age2;

	age1 = atoi(&str1[idx1 + 1]);
	age2 = atoi(&str2[idx2 + 1]);

	if (age1 == age2) {
		return 1;
	}
	else {
		return 0;
	}
}

int main(void) {
	char str1[20] = "";
	char str2[20];
	printf("첫번째 사람 정보 입력 : ");
	fgets(str1, sizeof(str1), stdin);
	str1[strlen(str1) - 1] = 0;
	printf("두번째 사람 정보 입력 : ");
	fgets(str2, sizeof(str2), stdin);
	str2[strlen(str2) - 1] = 0;

	if (CompName(str1, str2)) {
		puts("이름이 같습니다!");
	}
	else {
		puts("이름이 같지 않습니다!");
	}

	if (CompAge(str1, str2)) {
		puts("나이가 같습니다!");
	}
	else {
		puts("나이가 같지 않습니다!");
	}
	return 0;
}