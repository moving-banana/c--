#include <stdio.h>

int main(void){
    char word[100];
    int i=0;
    int n;
    printf("영단어 입력 : ");
    scanf("%s", word);
    printf("입력한 단 : %s \n", word);
    printf("아스키코드로 변경값 : ");
    printf("%d", word[0]);
    // while(word[i]!='\0'){
    //     printf("%c", word[i]);
    //     i++;
    // }
    return 0;
}