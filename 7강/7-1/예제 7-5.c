#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int num;
    int input;
    int total = 0;
    int i = 0;
    printf("���� � �Է��Ұ���?");
    scanf("%d", &num);
    printf(" %d����~ \n", num);
    while (i++ < num) {
        printf("�Է°�: ");
        scanf("%d", &input);
        total+= input;
    }
    printf("�� ���Ѱ��� : %d \n", total);
    printf("��հ��� : %f \n", (double)total / num);
    return 0;
}