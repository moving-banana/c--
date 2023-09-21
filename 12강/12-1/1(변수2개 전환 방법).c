#include <stdio.h>

int main(void) {
    int num1 = 10, num2 = 20;
    int* temp;
    int* ptr1 = &num1;
    int* ptr2 = &num2;

    (*ptr1) += 10;
    (*ptr2) -= 10;

    temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;

    printf("%d %d \n", *ptr1, *ptr2);
    return 0;
}