#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include<stdio.h>
int main(void)
{
	int arr[10], n, h = 0, j = 9;
	for (int i = 0; i < 10; i++)
	{
		printf("입력: ");
		scanf("%d", &n);
		if (n % 2 == 1)
		{
			arr[h] = n;
			h++;
		}
		else
		{
			arr[j] = n;
			j--;
		}
	}
	printf("배열 요소의 출력 : ");
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}