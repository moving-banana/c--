#include <stdio.h>

int main(void){
    char str[100];
    int i=0;
    printf("영단어 입력 : ");
    scanf("%s", str);
    printf("입력한 단어는? : %s \n", str);
    // printf("%c", str[1]);
    while(str[i]!='\0'){
        printf("%c", str[i]);
        i++;
    }
    return 0;
}

//나중에 풀어보자!!!!