#include <stdio.h>

int main(void) {
	int num;
	int i = 1;
	scanf("%d", &num);
	printf("????? ?? : %d \n", num);
	while (i < num+1) {
		printf("??��??? 3?? ??? %d ??�� : %d \n", i, num*i);
		i++;
	}
	return 0;
}            