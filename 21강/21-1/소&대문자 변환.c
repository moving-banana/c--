#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Trans(int n) {
	int gap = 'a' - 'A';
	if (n >= 'A' && n <= 'Z') {
		return n + gap;  //대문자의 ASCII+32 -> 소문자의 ASCII
	}
	else if (n >= 'a' && n <= 'z') {
		return n - gap;     //소문자의 ASCII-32 -> 대문자의 ASCII
	}
	else {
		return -1;
	}
}

int main(void) {
	int num;
	printf("알파벳 한개 입력 : ");
	num = getchar();
	num = Trans(num);
	putchar(num);
	if (num == -1) {
		puts("범위를 벗어난 입력입니다!");
		return -1;
	}
	return 0;
}