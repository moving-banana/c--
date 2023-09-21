#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp = fopen("mystory.txt", "at");
	if (fp == NULL) {
		puts("파일 오픈 실패!");
		return -1;
	}

	fputs("#즐겨먹는 음식 : 돈까스 \n", fp);
	fputs("#취미 : 축구 \n", fp);

	fclose(fp);
	return 0;
}