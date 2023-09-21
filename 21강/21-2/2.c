#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str1[20];
	char str2[20];
	char str3[40];

	printf("1번째 문자열 입력 :");
	fgets(str1, sizeof(str1), stdin);  //  simple\n
	str1[strlen(str1) - 1] = '\0';
	printf("2번째 문자열 입력 :");
	fgets(str2, sizeof(str2), stdin);  //  spring\n
	// printf("zz%d", str1[6]); -> 10출력 \n도 함꼐 복사 확인
	strcpy(str3, str1);  //  simple 6자리만 복사
	strcat(str3, str2);
	puts(str3);
	return 0;
}