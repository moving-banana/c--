#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];
	printf("문자열 입력 : ");
	gets(str);
	puts(str);
	int nums[100];
	int sum = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (48 <= str[i] && str[i] <= 57) {
			nums[i] = str[i];
			sum += nums[i];
		}
		else {
			nums[i] = 'a';
		}
	}
	printf("%d", sum);
	return 0;
}