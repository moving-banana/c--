#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HANGUL_SIZE 2

char kors[9][3] = { "일","이","삼","사","오","육","칠","팔","구" };
char nums[] = {1,2,3,4,5,6,7,8,9,0};
int idx1 = 0, idx2 = 0;

int KorToNum(char* str) {
    int ret = 0;	//리턴값을 저장
    int sLen = strlen(str);			//입력받은 스트링의 길이
    int digit = 0, unit = 0;		//digit=1의자리  unit=십,백,천,만 의 자리
    // int korLen = strlen(kor[0]);             korLen의값은 2 => 현재os에서 한글 한글자의 바이트값
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

void NumToKor(char* str) {
    char result[] = {0,};
    int sLen = strlen(str);
    printf("leng%d\n", sLen);

    for(idx1=0; idx1 < sLen; idx1++){
        printf("zz%c\n", str[idx1]);
    }

    for (idx1 = 0; idx1 < 10; idx1++) {
        if (str[idx1] == 1){
            result[idx1] = "만";
        }
        else if(str[idx1] == 2){
            result[idx1] = "천";
        }
        else if(str[idx1] == 2){
            result[idx1] = "백";
        }
        else if(str[idx1] == 2){
            result[idx1] = "십";
        }
    }

    for (idx1 = 0; idx1 < 10; idx1++) {
        if (str[idx1] == 1){
            result[idx1] = "일";
        }
        else if(str[idx1] == 2){
            result[idx1] = "이";
        }
        else if(str[idx1] == 3){
            result[idx1] = "삼";
        }
        else if(str[idx1] == 4){
            result[idx1] = "사";
        }
        else if(str[idx1] == 5){
            result[idx1] = "오";
        }
        else if(str[idx1] == 6){
            result[idx1] = "육";
        }
        else if(str[idx1] == 7){
            result[idx1] = "칠";
        }
        else if(str[idx1] == 8){
            result[idx1] = "팔";
        }
        else if(str[idx1] == 9){
            result[idx1] = "구";
        }
        else {
            result[idx1] = "";
        }
    }

    for(idx1=0; idx1 < strlen(result); idx1++){
        printf("ww%c\n", result[idx1]);
    }
}

int main(void) {
    char str1[21] = { 0, }, str2[21] = { 0, };
    char show[20];
    int num1 = 0, num2 = 0, sum = 0;
    // char fin;
    printf("물건의 가격은 0원부터 99999원까지!!\n\n");
    printf("물건의 가격 입력 : \n");
    scanf(" %s", &str1);
    scanf(" %s", &str2);
    printf("\n\n");
    num1 = KorToNum(str1);
    num2 = KorToNum(str2);
    sum = num1 + num2;

    sprintf(show, "%d", sum);
    // printf("zzz%s", show); show문자열 출력 정상
    printf("두 물건의 가격의 합은 : %s원\n", show);
    NumToKor(show);
    

    return 0;
}