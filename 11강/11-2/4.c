#include <stdio.h>

int main(void){
    char word[100];
    int i=0;
    int n;
    printf("���ܾ� �Է� : ");
    scanf("%s", word);
    printf("�Է��� �� : %s \n", word);
    printf("�ƽ�Ű�ڵ�� ���氪 : ");
    printf("%d", word[0]);
    // while(word[i]!='\0'){
    //     printf("%c", word[i]);
    //     i++;
    // }
    return 0;
}