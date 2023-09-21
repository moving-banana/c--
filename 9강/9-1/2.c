#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int CelToFah(int cel, int fah);
int FahToCel(int cel, int fah);

int main(void) {
	int cel, fah;
	printf("¼·¾¾ È­¾¾ °¢°¢ ÀÔ·Â : ");
	scanf("%d %d", &cel, &fah);
	printf("¼·¾¾%dC¸¦ È­¾¾·Î : %dF \n", cel, CelToFah(cel,fah));
	printf("È­¾¾%dF¸¦ ¼·¾¾·Î : %dC \n", fah, FahToCel(cel,fah));
	return 0;
}

int CelToFah(int cel, int fah) {
	fah = 1.8 * cel + 32;
	return fah;
}
int FahToCel(int cel, int fah) {
	cel = (fah - 32) / 1.8;
	return cel;
}


