#include <stdio.h>

int main(void){
    char str[100];
    int i=0;
    printf("���ܾ� �Է� : ");
    scanf("%s", str);
    printf("�Է��� �ܾ��? : %s \n", str);
    // printf("%c", str[1]);
    while(str[i]!='\0'){
        printf("%c", str[i]);
        i++;
    }
    return 0;
}

//���߿� Ǯ���!!!!