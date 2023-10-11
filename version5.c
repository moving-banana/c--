#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define HANGUL_SIZE 3
#define HANGUL_NUM_MAX 9
#define MAX_INPUT_LENGTH 100
#define KORNUM_LENGTH 21
#define ARRAY_SIZE 200  // 입력 값의 최대 사이즈 지정

char kors[HANGUL_NUM_MAX][HANGUL_SIZE + 1] = { "일","이","삼","사","오","육","칠","팔","구" };
int minus = false;       //한글계산기 음수값 컨트롤
int won = false;        //"원"입력시
int NumHas = false;

void chooseMod();

bool EscPressed() {
    int putEsc = 0;
    while ((putEsc = getchar()) != '\n' && putEsc != EOF) {
        if (putEsc == 27) {  // 27은 ESC 키의 ASCII 코드입니다
            return true;
        }
    }
    return false;
}

void restartProgram() {
    // 입력 버퍼를 비워줍니다.
    int putEsc = 0;
    while ((putEsc = getchar()) != '\n' && putEsc != EOF) {}

    // 메뉴를 다시 보여줍니다.
    chooseMod();
}

void stopProgram(const char* input) {
    printf("종료를 원하시면 exit를 입력하세요.\n");
    if (input[0] == 'e' && input[1] == 'n' && input[2] == 'd') {
        // end라는 값을 입력받았는지 확인하고, 입력받았으면 프로그램을 종료시킨다.
        printf("프로그램을 종료합니다.\n");
        exit(0);
    }
}

//숫자가 포함되어 있는지 확인하는 함수
int hasInteger(const char *inputString) {
    // 문자열의 각 문자를 순회하며 숫자인지 확인합니다.
    for (int i = 0; inputString[i] != '\0'; ++i) {
        // 각 문자가 '0'부터 '9' 사이에 있는지 확인하여 숫자인지 판단합니다.
        if (inputString[i] >= '0' && inputString[i] <= '9') {
            return true; // 숫자가 포함되어 있으면 참을 반환합니다.
        }
    }
    return false; // 숫자가 포함되어 있지 않으면 거짓을 반환합니다.
}

//입력받은 한글을 정수로 변환
int KorToNum(const char* inputStr) {       
    int retValue = 0;   //리턴값을 저장
    int sLen = strlen(inputStr);         //입력받은 스트링의 길이
    int idx1 = 0, idx2 = 0;
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

        if(strcmp(inputStr + idx1, "원") == 0){
            won = true;
        }
    }

    retValue += digit;

    return retValue;
}

//문자열로저장된 수를 한글문자열로 변환
void NumToKor(const char* inputStr) {
    char unitKor[HANGUL_NUM_MAX+1][HANGUL_SIZE + 1] = { "", "십", "백", "천" , "만" , "십" , "백" , "천" , "억" , "십"};
    int idx1 = 0, idx2 = 0;

    int tmp = 0;        //일시적으로 인덱스값을 저장
    int ctrl = 0;       //if문 조절해주는 변수

    printf("연산결과는 : ");

    if(minus == true){  //음수값일때 앞에 - 를 붙여주자
        printf("-");
        minus=false;
    }

    for (idx1 = 0; idx1 < strlen(inputStr); idx1++) {
        if (inputStr[idx1] == '0') {
            if(strlen(inputStr) - idx1 - 1 == 8) {
                if (ctrl != 0) printf("억");
                ctrl = 0;
            }
            else if (strlen(inputStr) - idx1 - 1 == 4) {      //십만 이상일때 idx1=1의값이 0이면
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

    if(won == true){
        printf("원");
        won = false;
    }

    printf("\n");
}

//한글 계산기
void KorCalculator() {
    char input[MAX_INPUT_LENGTH]; // 입력을 저장할 문자열 배열
    char Kornum1[KORNUM_LENGTH] = { 0, }, Kornum2[KORNUM_LENGTH] = { 0, };
    char operator = 0; // 연산 기호를 저장할 변수
    long long int sum = 0;     //곱하기값이 21억을 넘어갈때를 대비

    while(1){
        // 문자열과 연산 기호를 한 줄로 입력받음
        printf("\n");
        printf("계산식을 입력하세요 (예: 이천삼백사십오+이천삼백사십오): ");
        fgets(input, sizeof(input), stdin);

        // 줄 바꿈 문자를 NULL문자로 변경하여 입력을 처리
        input[strcspn(input, "\n")] = '\0';

        // 문자열과 연산 기호를 분리
        sscanf(input, "%[^+-*/]%c%[^\n]", Kornum1, &operator, Kornum2);

        if (hasInteger(input)) {
            NumHas = true;
        } else {
            NumHas = false;
        }

        if (NumHas == false)
        {
            int num1 = KorToNum(Kornum1);
            int num2 = KorToNum(Kornum2);

            // 연산 수행
            switch (operator) {
                case '+':
                    sum = num1 + num2;
                    break;
                case '-':
                    sum = num1 - num2;
                    break;
                case '*':
                    sum = (long long)num1 * num2;
                    break;
                case '/':
                    sum = num1 / num2;
                    break;
                default:
                    printf("잘못된 입력입니다 다시입력하세요.\n");
            }

            char show[MAX_INPUT_LENGTH] = { 0, };

            if(sum < 0){
                sum = -sum;
                minus = true;
            }

            sprintf(show, "%lld", sum);   //sum 변수에 저장된 정수 값을 문자열로 변환하여 show 문자열 배열에 저장

            // 결과 출력
            NumToKor(show);
            printf("\n");
            printf("(이전단계로 돌아가려면 esc키를 누르세요)\n");
            printf("(계속진행하려면 아무키나 입력하세요)\n");

            if (EscPressed()) {
                restartProgram();
                break;
            }
        }
        else{
            printf("\n");
            printf("잘못된 입력입니다.\n");
            printf("\n");
            printf("(이전단계로 돌아가려면 esc키를 누르세요)\n");
            stopProgram(input);
            printf("(계속진행하려면 아무키나 입력하세요)\n");

            if (EscPressed()) {
                restartProgram();
                break;
            }
        }
    }
}

//숫자 계산기
void NumCalculator(){
    int num1 = 0, num2 = 0;
    char input[ARRAY_SIZE] = {0,};
    char operator = 0;

    printf("숫자 계산기!!\n\n");

    while(1){
        printf("\n");
        printf("수식을 입력하세요 (예: 5+3): ");
        fgets(input, sizeof(input), stdin);

        // 입력된 수식에서 숫자와 연산자 추출
        sscanf(input, "%d%c%d", &num1, &operator, &num2);

        if (hasInteger(input)) {
            NumHas = true;
        } else {
            NumHas = false;
        }

        // 연산 수행
        switch (operator) {
            case '+':
                printf("연산결과는 :");
                printf("%d\n\n", num1 + num2);
                printf("(이전단계롤 돌아가려면 esc키를 누르세요)\n");
                printf("(계속진행하려면 아무키나 입력하세요)\n");
                break;
            case '-':
                printf("연산결과는 :");
                printf("%d\n\n", num1 - num2);
                printf("(이전단계롤 돌아가려면 esc키를 누르세요)\n");
                printf("(계속진행하려면 아무키나 입력하세요)\n");
                break;
            case '*':
                printf("연산결과는 :");
                printf("%lld\n\n", (long long)num1 * num2);
                printf("(이전단계롤 돌아가려면 esc키를 누르세요)\n");
                printf("(계속진행하려면 아무키나 입력하세요)\n");
                break;
            case '/':
                printf("연산결과는 :");
                if (num2 != 0) {
                    printf("%lf\n\n", (float)num1 / num2); // 나눗셈 결과를 float로 변환하여 저장
                    printf("(이전단계롤 돌아가려면 esc키를 누르세요)\n");
                    printf("(계속진행하려면 아무키나 입력하세요)\n");
                } else {
                    printf("0으로 나눌 수 없습니다.\n");
                }
                break;
            default:
                printf("잘못된 연산자입니다.\n");
                printf("다시 입력하세요!!!\n");
                break;
        }
        
        memset(&input[0], 0, sizeof(input));

        if (EscPressed()) {
            restartProgram();
            break;
        }
    }
}

void chooseMod(){
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
}

int main() {
	chooseMod();
	return 0;
}