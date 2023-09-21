#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str1[20] = "First~";
	char str2[20] = "Second";

	// char str3[20]="Simple num : ";   <- 일반저긴 str에는 공백문자가 선언X!!!
	char str3[20] = "Simple num :";
	char str4[20] = "1234567890";

	//1
	strcat(str1, str2);  //문자열 복사해서 뒤에 붙이기
	puts(str1);

	//2
	strncat(str3, str4, 7);
	puts(str3);
	return 0;
}