#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void What(int w) {
    if (w == 1) {
        printf("ȸ���Դϴ�!\n");
    }
    else {
        printf("ȸ���� �ƴմϴ�!\n");
    }
}

int main(void) {
    int i, w;
    int len = 0;
    char word[100];
    printf("�Է� : ");
    scanf("%s", word);
    for (i = 0; word[i] != '\0'; i++)
    {
        len++;
    }

    printf("%d\n", len);
    for (i = 0; word[i] != '\0'; i++) {
        if (word[i] == word[len - 1 - i]) {
            w = 1;
        }
        else {
            w = 0;
        }
    }
    What(w);
    return 0;
}