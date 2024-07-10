#include <stdio.h>
#include <conio.h>
int main() {
	int a, b,c;
	printf("Nhap a:");
	scanf_s("%d", &a);
	printf("Nhap b:");
	scanf_s("%d", &b);
	printf("Nhap c:");
	scanf_s("%d", &c);
	float d = c / (a - b);
	printf("Gia tri cua c/(a-b):%.2f", d);
	getch();
	return 0;
}