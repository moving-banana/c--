#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HANGUL_SIZE 2

char kors[9][3] = { "일","이","삼","사","오","육","칠","팔","구" };
int idx1 = 0, idx2 = 0;

int KorToNum(char* str) {       //입력받은 한글을 정수로 변환
    int ret = 0;   //리턴값을 저장
    int sLen = strlen(str);         //입력받은 스트링의 길이
    int digit = 0, unit = 0;      //digit=1의자리  unit=십,백,천,만 의 자리
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
        else {           //입력받은 스트링과 unit을 비교하여 해당하지 않을경우 각각의 숫자를 digit에 저장
            for (idx2 = 0; idx2 < sLen; idx2++) {
                if (strncmp(str + idx1, kors[idx2], HANGUL_SIZE) == 0) {
                    digit = idx2 + 1;
                    break;
                }
            }
        }

        if (unit >= 10) {        //저장된 digit값과 unit값을 통해 입력된값을 정수로 ret에 저장
            digit = (digit == 0 ? 1 : digit);
            ret += digit * unit;
            digit = unit = 0;
        }
    }

    ret += digit;

    return ret;
}

int NumToKor(char* str){    //문자열로저장된 수를 한글문자열로 변환
    char unitKor[6][4] = { "", "십", "백", "천" , "만" ,"십" };

    int tmp = 0;        //일시적으로 인덱스값을 저장
    int cont = 0;       //if문 조절해주는 변수
    char newArr[25]={0,};

    printf("두 물건의 가격의 합은 : ");
    for (idx1 = 0; idx1 < strlen(str); idx1++) {
        if (str[idx1] == '0') {
            if (strlen(str) - idx1 - 1 == 4) {      //십만 이상일때 idx1=1의값이 0이면
                if (cont != 0) {
                    printf("만");
                    newArr[idx1*2]="만";
                }
                cont = 0;
            }
            continue;
        }

        //문자열로 저장된 str을 int형으로 변환후 0에 해당하는 ascii코드값(문자0 = 48)을 빼준다
        tmp = str[idx1] - 48;
        cont += 1;
        printf("%s%s", kors[tmp - 1], unitKor[strlen(str) - idx1 - 1]);   //나머지자리
        newArr[idx1*2]=kors[tmp - 1];
        newArr[idx1*2+1]=unitKor[strlen(str) - idx1 - 1];
    }
    printf("원\n");
    return 0;
}

int main(void) {
    char str1[21] = { 0, }, str2[21] = { 0, };
    char show[20] = {0, };
    int num1 = 0, num2 = 0, sum = 0;

    printf("물건의 가격은 0원부터 99999원까지!!\n\n");
    printf("물건의 가격 각각 입력 : \n");
    scanf(" %s", &str1);
    scanf(" %s", &str2);
    printf("\n\n");

    num1 = KorToNum(str1);
    num2 = KorToNum(str2);
    sum = num1 + num2;
    sprintf(show, "%d", sum);
    // printf("두 물건의 가격의 합은 : %s원\n", show);
    NumToKor(show);

    // printf("두 물건의 가격의 합은 : %s원\n", show);

    return 0;
}