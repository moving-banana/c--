#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char nums[9][4] = { "일","이","삼","사","오","육","칠","팔","구" };

if(입력한 input이 2개){
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
    result = sum;
}
else if (입력한 input이 3개이상){
    switch (operator) {
        case '+':
            sum = result + 새로입력한 input;
            break;
        case '-':
            sum = result - 새로입력한 input;
            break;
        case '*':
            sum = (long long)result * 새로입력한 input;
            break;
        case '/':
            sum = result / 새로입력한 input;
            break;
        default:
            printf("잘못된 입력입니다 다시입력하세요.\n");
    }
    result =sum;
}

int ChangeValue(char* str) {
    int ret = 0;
    int sLen = strlen(str);
    int n = 0, unit = 0;
    int korLen = strlen(nums[0]);
    for (int i = 0; i < sLen; i += korLen) {
        if (strncmp(str + i, "만", korLen) == 0) {
            unit = 10000;
        }
        else if (strncmp(str + i, "천", korLen) == 0) {
            unit = 1000;
        }
        else if (strncmp(str + i, "백", korLen) == 0) {
            unit = 100;
        }
        else if (strncmp(str + i, "십", korLen) == 0) {
            unit = 10;
        }
        else {
            for (int j = 0; j < sLen; j++) {
                if (strncmp(str + i, nums[j], korLen) == 0) {
                    n = j + 1;
                    break;
                }
            }
        }

        if (unit >= 10) {
            n = (n == 0 ? 1 : n);
            ret += n * unit;
            n = unit = 0;
        }
    }

    ret += n;

    return ret;
}

int main(void) {
    char str1[21], str2[21];
    int num1, num2, result;
    printf("물건의 가격은 0원부터 99999원까지!!\n\n");
    printf("첫번째 물건의 가격 입력 : ");
    scanf(" %s", &str1);
    printf("두번째 물건의 가격 입력 : ");
    scanf(" %s", &str2);

    num1 = ChangeValue(str1);
    num2 = ChangeValue(str2);
    result = num1 + num2;
    // printf("%d\n", num1);
    // printf("%d\n", num2);
    printf("두 물건의 가격의 합은 : %d원\n", result);

    return 0;
}