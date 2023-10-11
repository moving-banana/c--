#include <stdio.h>
#include <string.h>

#define HANGUL_SIZE 3
#define HANGUL_NUM_MAX 9

#define MAX_STRINGS 100
#define MAX_STRING_LENGTH 100
#define MAX_OPERATORS 100

char kors[HANGUL_NUM_MAX][HANGUL_SIZE + 1] = { "일","이","삼","사","오","육","칠","팔","구" };

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
    }

    retValue += digit;

    return retValue;
}

// 문자열을 분리하고 정적으로 메모리를 할당하여 저장하는 함수
void splitString(char *input, char strings[MAX_STRINGS][MAX_STRING_LENGTH], char operators[MAX_OPERATORS], int *count) {
    char *token = strtok(input, "+-*/");
    *count = 0;

    while (token != NULL && *count < MAX_STRINGS - 1) {
        // 문자열 복사
        strcpy(strings[*count], token);

        // 연산자 복사
        operators[*count] = input[token - input + strlen(token)];

        (*count)++;
        token = strtok(NULL, "+-*/");
    }
}

int main() {
    char input[100];
    char strings[MAX_STRINGS][MAX_STRING_LENGTH];
    char num[MAX_STRINGS][MAX_STRING_LENGTH];
    char operators[MAX_OPERATORS];
    int count;

    printf("수식을 입력하세요 (나가려면 엔터 키를 누르세요):\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        // 입력 문자열에서 줄 바꿈 문자를 제거
        input[strcspn(input, "\n")] = '\0';

        // 입력이 비어 있는지 확인 (엔터 키만 눌렸을 경우)
        if (strlen(input) == 0) {
            printf("프로그램을 종료합니다. 안녕히 계세요!\n");
            break;
        }

        // 문자열 분리
        splitString(input, strings, operators, &count);

        //분리된 문자열 숫자로 변환
        int num[MAX_STRINGS]; // 숫자를 저장할 배열 선언
        for (int i = 0; i < count; i++) {
            num[i] = KorToNum(strings[i]); // KorToNum 함수를 호출하여 문자열을 숫자로 변환
        }

        // 변환된 숫자 출력 (예시로 출력함)
        for (int i = 0; i < count; i++) {
            printf("AA%d", num[i]);
        }
        printf("\n");
        printf("%s", num);

        // 분리된 값 출력
        printf("분리된 문자열:\n");
        for (int i = 0; i < count; i++) {
            printf("%s ", strings[i]);
            if (i < count - 1) {
                printf("%c ", operators[i]);
            }
        }
        printf("\n");
    }

    return 0;
}