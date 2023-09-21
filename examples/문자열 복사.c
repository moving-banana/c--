#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str1[20] = "1234567890";
	char str2[20];
	char str3[5];

	//1
	strcpy(str2, str1);
	puts(str2);

	//2
	// strncpy(str3, str1, sizeof(str3));
	// puts(str3);
	// 위의 호출은 에러 발생!!
	// strncpy는 3번째 인자(sizeof(str3))의 길이만큼 복사
	//  -> str3에는 null문자가 없어 문자열의 끝을 인식하지 못한다. 

	//3
	strncpy(str3, str1, sizeof(str3) - 1);
	str3[sizeof(str3) - 1] = 0;
	puts(str3);
	return 0;
	// sizeof(stre)-1 만큼을 복사해야 문자열의 마지막에 null문자 저장 가능!!!
}