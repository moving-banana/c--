#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	FILE* fp = fopen("mystory.txt", "wt");
	if (fp == NULL) {
		puts("파일 오픈 실패!");
		return -1;
	}

	fputs("#이름 : 임진우 \n", fp);
	fputs("#주민번호 : 980622-1032111 \n", fp);
	fputs("#전화번호 : 010-5877-8585 \n", fp);

	fclose(fp);
	return 0;
}