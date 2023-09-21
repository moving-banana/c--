#include <stdio.h>

int main(void) {
    int arr[5] = { 1,2,3,4,5 };
    int* ptr = &arr[0];
    int i;
    for (i = 0; i < 5; i++) {
        ptr[i] += 2;
        printf("%d", ptr[i]);
    }
    return 0;
}