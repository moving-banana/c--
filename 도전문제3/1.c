#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void){
    int arr1[4][4];
    int i,j;
    for(i=0; i<16; i++){
        arr1[i/4][i%4]=i+1;
    }
    int arr2, arr3, arr4;
    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            printf("%4d", arr1[i][j]);
        }
        printf("\n\n");
    }
    printf("    회전 1회! \n\n");
    for(j=0; j<4; j++){
        for(i=3; i>=0; i--){
            arr2=arr1[i][j];
            printf("%4d", arr2);
        }
        printf("\n\n");
    }
    printf("    회전 2회! \n\n");
    for(i=3; i>=0; i--){
        for(j=3; j>=0; j--){
            arr3=arr1[i][j];
            printf("%4d", arr3);
        }
        printf("\n\n");
    }
    printf("    회전 3회! \n\n");
    for(j=3; j>=0; j--){
        for(i=0; i<4; i++){
            arr4=arr1[i][j];
            printf("%4d", arr4);
        }
        printf("\n\n");
    }
    return 0;
}