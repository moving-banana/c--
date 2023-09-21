#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ClearLineFromReadBuffer(void) {    // \n이 읽힐때까지 입력버퍼에 저장된값을 지우는 함수
	while (getchar() != '\n');
}

int main(void) {
	char perID[7];
	char name[10];

	fputs("주민번호 앞 6자리 입력 : ", stdout);
	fgets(perID, sizeof(perID), stdin);
	ClearLineFromReadBuffer();   // \n이 읽힐때까지 입력버퍼에 저장된값을 지우는 함수

	fputs("이름 입력 : ", stdout);
	fgets(name, sizeof(name), stdin);

	printf("주민번호 앞자리 : %s \n", perID);
	printf("이름 : %s \n", name);
	return 0;
}