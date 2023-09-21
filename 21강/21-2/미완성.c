#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int CalToSP(char n[]) { //공백까지의 거리 계산
	int dif = 0;
	for (int i = 0; i < 100; i++) {
		dif++;
		if (n[i] == 32)
			break;
	}
	return dif;
}

int main(void) {
	char str1[20];
	char str2[20];
	printf("문자열 입력 1: ");
	gets(str1);
	str1[strlen(str1) - 1] = '0';
	printf("문자열 입력 2: ");
	gets(str2);
	str2[strlen(str2) - 1] = '0';
	if (CalToSP(str1) != CalToSP(str2)) {
		puts("두 사람의 이름은 다릅니다!");
	}
	if (CalToSP(str1) == CalToSP(str2)) {
		if (strcmp(str1, str2, CalToSP(str1) - 1) == 0) {
			puts("두 사람의 이름은 같습니다!");
		}
		else {
			puts("두 사람의 이름은 다릅니다!");
		}
	}
	// int dif1=0, dif2=0;
	// for(int i=0; i<100; i++){
	// 	dif1++;
	// 	if(str1[i]==32)
	// 	break;
	// }
	// printf("%d\n", dif1);
	// for(int i=0; i<100; i++){
	// 	dif2++;
	// 	if(str2[i]==32)
	// 	break;
	// }
	// printf("%d\n", dif2);
	// if(dif1!=dif2){
	// 	puts("두 사람의 나이는 다릅니다!");
	// }


	// if (!strcmp(str1, str2)) {
	// 	puts("두 문자열은 완벽히 동일합니다!");
	// }
	// else {
	// 	puts("두 문자열은 동일하지 않습니다!");

	// 	if (!strncmp(str1, str2, 4)) {
	// 		puts("그러나 앞 네글자는 동일합니다");
	// 	}
	// }
	return 0;
}