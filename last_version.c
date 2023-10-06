#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HANGUL_SIZE 3
#define HANGUL_NUM_MAX 9

char kors[HANGUL_NUM_MAX][4] = { "일","이","삼","사","오","육","칠","팔","구" };
int idx1 = 0, idx2 = 0;

int KorToNum(const char* str) {       //입력받은 한글을 정수로 변환
    int retValue = 0;   //리턴값을 저장

    int sLen = strlen(str);         //입력받은 스트링의 길이
    // printf("%d", strlen(str));     3
    int digit = 0, unit = 0;      //digit=각자리의 정수  unit=십,백,천,만 의 자리
    for (idx1 = 0; idx1 < sLen; idx1 += HANGUL_SIZE) {            //입력받은 스트링과 unit을 비교하여 해당값 저장
        if (strncmp(str + idx1, "만", HANGUL_SIZE) == 0) {
            unit = 10000;
        }
        else if (strncmp(str + idx1, "천", HANGUL_SIZE) == 0) {
            unit = 1000;
        }
        else if (strncmp(str + idx1, "백", HANGUL_SIZE) == 0) {
            unit = 100;
        }
        else if (strncmp(str + idx1, "십", HANGUL_SIZE) == 0) {
            unit = 10;
        }
        else {           //단위가아닌 각자리의 정수일때
            for (idx2 = 0; idx2 < HANGUL_NUM_MAX; idx2++) {
                if (strncmp(str + idx1, kors[idx2], HANGUL_SIZE) == 0) {
                    digit = idx2 + 1;
                    break;
                }
            }
        }

        if (unit >= 10) {        //단위값을 가르킬때
            digit = (digit == 0 ? 1 : digit);
            retValue += digit * unit;
            digit = 0;
            unit = 0;
        }
    }

    retValue += digit;

    return retValue;
}

int NumToKor(char* str) {    //문자열로저장된 수를 한글문자열로 변환
    char unitKor[6][4] = { "", "십", "백", "천" , "만" ,"십" };

    int tmp = 0;        //일시적으로 인덱스값을 저장
    int cont = 0;       //if문 조절해주는 변수

    printf("연산결과는 : ");
    for (idx1 = 0; idx1 < strlen(str); idx1++) {
        if (str[idx1] == '0') {
            if (strlen(str) - idx1 - 1 == 4) {      //십만 이상일때 idx1=1의값이 0이면
                if (cont != 0) printf("만");
                cont = 0;
            }
            continue;
        }

        //문자열로 저장된 str을 int형으로 변환후 0에 해당하는 ascii코드값(문자0 = 48)을 빼준다
        tmp = str[idx1] - 48;
        cont += 1;
        printf("%s%s", kors[tmp - 1], unitKor[strlen(str) - idx1 - 1]);   //나머지자리 
    }
    return 0;
}

int main(void) {
    char Kornum1[21] = { 0, }, Kornum2[21] = { 0, };
    char show[32] = { 0, };
    int num1 = 0, num2 = 0, sum = 0;
    char opsym = 0;

    printf("0부터 99999까지의 한글 계산기!!\n\n");
    while (1)
    {
        scanf("%s", Kornum1);
        scanf("%s", &opsym);
        scanf("%s", Kornum2);
        printf("\n\n");

        num1 = KorToNum(Kornum1);
        num2 = KorToNum(Kornum2);

        switch (opsym) {  //char a의 값에 따라서 case를 설정
        case '+': //char a의 값이 +일경우 +연산을 한다.
            sum = num1 + num2;
            sprintf(show, "%d", sum);
            break;
        case '-': //char a의 값이 -일경우 -연산을 한다.
            sum = num1 - num2;
            sprintf(show, "%d", sum);
            break;
        default:
            sprintf(show, "계산할 수 없음");
            break;
        }


        NumToKor(show);
    }

    return 0;
}