#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char str[30];
	int ch;
	FILE* fp = fopen("mystory.txt", "rt");
	if (fp == NULL) {
		puts("파일 오픈 실패!");
		return -1;
	}
	while (fgets(str, sizeof(str), fp) != NULL) {
		printf("%s", str);
	}
	fclose(fp);
	return 0;
}