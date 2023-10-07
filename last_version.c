#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define HANGUL_SIZE 3
#define HANGUL_NUM_MAX 9

char kors[HANGUL_NUM_MAX][4] = { "일","이","삼","사","오","육","칠","팔","구" };
int idx1 = 0, idx2 = 0;
char ex = 'n';

int KorToNum(const char* inputStr) {       //입력받은 한글을 정수로 변환
    int retValue = 0;   //리턴값을 저장
    int sLen = strlen(inputStr);         //입력받은 스트링의 길이
    // printf("%d", strlen(inputStr));     3
    int digit = 0, unit = 0;      //digit=각자리의 정수  unit=십,백,천,만 의 자리
    for (idx1 = 0; idx1 < sLen; idx1 += HANGUL_SIZE) {            //입력받은 스트링과 unit을 비교하여 해당값 저장
        if (strncmp(inputStr + idx1, "만", HANGUL_SIZE) == 0) {
            unit = 10000;
        }
        else if (strncmp(inputStr + idx1, "천", HANGUL_SIZE) == 0) {
            unit = 1000;
        }
        else if (strncmp(inputStr + idx1, "백", HANGUL_SIZE) == 0) {
            unit = 100;
        }
        else if (strncmp(inputStr + idx1, "십", HANGUL_SIZE) == 0) {
            unit = 10;
        }
        else {           //단위가아닌 각자리의 정수일때 (10미만의 수)
            for (idx2 = 0; idx2 < HANGUL_NUM_MAX; idx2 ++) {
                if (strncmp(inputStr + idx1, kors[idx2], HANGUL_SIZE) == 0) {
                    digit = idx2 + 1;
                    break;
                }
            }
        }

        if (unit >= 10) {        //단위값을 가르킬때 (10이상의 수)
            digit = (digit == 0 ? 1 : digit);
            retValue += digit * unit;
            digit = 0;
            unit = 0;
        }
    }

    retValue += digit;

    return retValue;
}

//문자열로저장된 수를 한글문자열로 변환
void NumToKor(const char* inputStr) {
    char unitKor[6][4] = { "", "십", "백", "천" , "만" ,"십" };

    int tmp = 0;        //일시적으로 인덱스값을 저장
    int ctrl = 0;       //if문 조절해주는 변수

    printf("연산결과는 : ");
    for (idx1 = 0; idx1 < strlen(inputStr); idx1++) {
        if (inputStr[idx1] == '0') {
            if (strlen(inputStr) - idx1 - 1 == 4) {      //십만 이상일때 idx1=1의값이 0이면
                if (ctrl != 0) printf("만");
                ctrl = 0;
            }
            continue;
        }

        //문자열로 저장된 str을 int형으로 변환후 0에 해당하는 ascii코드값(문자0 = 48)을 빼준다
        tmp = inputStr[idx1] - 48;
        ctrl += 1;
        printf("%s%s", kors[tmp - 1], unitKor[strlen(inputStr) - idx1 - 1]);   //나머지자리 
    }
    printf("\n");
}

//한글 계산기
void KorCalculator() {
    char input[100]; // 입력을 저장할 문자열 배열
    char Kornum1[21] = { 0, }, Kornum2[21] = { 0, };
    char opsym = 0; // 연산 기호를 저장할 변수

    while(1){
        // 문자열과 연산 기호를 한 줄로 입력받음
        printf("계산식을 입력하세요 (예: 이천삼백사십오+이천삼백사십오): ");
        fgets(input, sizeof(input), stdin);

        // 줄 바꿈 문자를 제거하여 입력을 처리
        input[strcspn(input, "\n")] = '\0';

        // 문자열과 연산 기호를 분리
        sscanf(input, "%[^+-*/]%c%[^\n]", Kornum1, &opsym, Kornum2);

        int num1 = KorToNum(Kornum1);
        int num2 = KorToNum(Kornum2);
        int sum = 0;

        // 연산 수행
        switch (opsym) {
            case '+':
                sum = num1 + num2;
                break;
            case '-':
                sum = num1 - num2;
                break;
            case '*':
                sum = num1 * num2;
                break;
            case '/':
                sum = num1 / num2;
                break;
            default:
                printf("잘못된 연산 기호입니다.\n");
        }

        char show[32] = { 0, };
        sprintf(show, "%d", sum);

        // 결과 출력
        NumToKor(show);
    }

}

//숫자 계산기
void NumCalculator(void){
    int num1 = 0, num2 = 0;
    char opsym = 0;

    printf("숫자 계산기!!\n\n");

    while(1){
        char input[50];
        int num1, num2;
        char operator;

        printf("\n");
        printf("수식을 입력하세요 (예: 5+3): ");
        fgets(input, sizeof(input), stdin);

        // 입력된 수식에서 숫자와 연산자 추출
        sscanf(input, "%d%c%d", &num1, &operator, &num2);

        // 연산 수행
        switch (operator) {
            case '+':
                printf("연산결과는 :");
                printf("%d\n", num1 + num2);
                break;
            case '-':
                printf("연산결과는 :");
                printf("%d\n", num1 - num2);
                break;
            case '*':
                printf("연산결과는 :");
                printf("%d\n", num1 * num2);
                break;
            case '/':
                printf("연산결과는 :");
                if (num2 != 0) {
                    printf("%lf\n", (float)num1 / num2); // 나눗셈 결과를 float로 변환하여 저장
                } else {
                    printf("0으로 나눌 수 없습니다.\n");
                }
                break;
            default:
                printf("잘못된 연산자입니다.\n");
                printf("다시 입력하세요!!!\n");
                break;
        }
    }
}

int main() {
	char choice = 0;
	bool flag = true;

	while(flag == true){
		printf(" 어떤 계산기를 사용하시겠습니까? \n\n");
		printf(" 1 : 숫자 계산기\n");
		printf(" 2 : 한글 계산기\n");
		printf(" 1,2 중 하나 입력! -> ");
		scanf("%s", &choice);
        getchar();
		printf("\n");

		if (choice == '1') {
			printf("숫자 계산기 실행!!\n");
            NumCalculator();
			flag = false;
			break;
		}
		else if (choice == '2') {
			printf("한글 계산기 실행!!\n");
            KorCalculator();
			flag = false;
			break;
		}
		else {
			printf("다시 입력하세요!!!\n");
			flag = true;
		}
	}

	return 0;
}