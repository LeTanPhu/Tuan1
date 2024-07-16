#include<conio.h>
#include<stdio.h>
void tinh_Tong_Hieu_Tich_Thuong(float* a, float* b) {
	float tong = *a + *b;
	float hieu = *a - *b;
	float tich = *a * *b;
	float thuong = *a / *b;
	printf("\nTong la :%.2f va dia chi la :%x", tong, &tong);
	printf("\nHieu la :%.2f va dia chi la :%x", hieu, &hieu);
	printf("\nTich la :%.2f va dia chi la :%x", tich, &tich);
	printf("\nTHuong la :%.2f va dia chi la :%x", thuong, &thuong);
}
int main() {
	float a, b;
	float* pa = &a;
	float* pb = &b;
	printf("Nhap vao a:");
	scanf("%f", &a);
	printf("Nhap vao b:");
	scanf("%f", &b);
	tinh_Tong_Hieu_Tich_Thuong(pa, pb);
}