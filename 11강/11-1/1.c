#include <stdio.h>

int Calbig(int num1,int num2,int num3,int num4,int num5){
    int arr1[]={num1,num2,num3,num4,num5};
    int max=arr1[0];
    int i;
    for(i=0; i<5; i++){
        if(arr1[i]>max)
            max=arr1[i];
    }
    return max;
}

int CalSmall(int num1,int num2,int num3,int num4,int num5){
    int arr1[]={num1,num2,num3,num4,num5};
    int min=arr1[0];
    int i;
    for(i=0; i<5; i++){
        if(arr1[i]<min)
            min=arr1[i];
    }
    return min;
}

int CalTotal(int num1,int num2,int num3,int num4,int num5){
    int total;
    total=num1+num2+num3+num4+num5;
    return total;
}

int main(void){
    int num1,num2,num3,num4,num5;
    int i;
    printf("5???? ???? ???: \n");
    scanf("%d %d %d %d %d", &num1, &num2, &num3, &num4, &num5);
    int arr1[]={num1,num2,num3,num4,num5};
    printf("?ò÷ : ");
    for(i=0; i<5; i++){
        printf(" %d", arr1[i]);
    }
    printf("\n");
    printf("??? ??? : %d \n", Calbig(num1,num2,num3,num4,num5));
    printf("???? ??? : %d \n", CalSmall(num1,num2,num3,num4,num5));
    printf("??¡Æ??? ?? : %d \n", CalTotal(num1,num2,num3,num4,num5));
    return 0;
}