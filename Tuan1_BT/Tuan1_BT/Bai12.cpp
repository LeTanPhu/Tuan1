#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstdlib> 
#include<stdlib.h>
struct PhanSo
{
	int tu, mau;
};
void Nhap1PS(PhanSo* ps) {
	printf("\nNhap tu so:");
	scanf("%d", &ps->tu);
	try
	{
		printf("\nNhap mau so:");
		scanf("%d", &ps->mau);
		if (ps->mau == 0) throw 101;
	}
	catch (int error)
	{
		if (error == 101) printf("\nMau so khong hop le!");
	}
}
void Xuat1PS(PhanSo ps) {
	printf("\n%d/%d", ps.tu, ps.mau);
}
void NhapMangPS(PhanSo* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("Nhap phan so thu %d:\n", i + 1);
		Nhap1PS(&arr[i]);
	}
}
void XuatMangPS(PhanSo* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		printf("\nPhan so thu %d: ", i + 1);
		Xuat1PS(arr[i]);
	}
}
void timMax(PhanSo* arr, int n) {
	float max = 0;
	int tumax, maumax;
	for (int i = 0; i < n; i++)
	{
		float x = (float)arr[i].tu / arr[i].mau;
		if (max < x) {
			max = x;
			tumax = arr[i].tu;
			maumax = arr[i].mau;
		}
	}
	printf("\nPhan so lon nhat:%d/%d", tumax, maumax);
}
void timMin(PhanSo* arr, int n) {
	int min = INT_MAX;
	int tumin, maumin;
	for (int i = 0; i < n; i++)
	{
		float x = (float)arr[i].tu / arr[i].mau;
		if (min > x) {
			min = x;
			tumin = arr[i].tu;
			maumin = arr[i].mau;
		}
	}
	printf("\nPhan so nho nhat:%d/%d", tumin, maumin);
}
void xoaPhanTu(PhanSo* arr, int n, int k) {
	if (k < 0 || k >= n) {
		printf("\nVi tri xoa khong hop le.");
		return;
	}
	for (int i = k; i < n - 1; i++) {
		arr[i] = arr[i + 1];
	}
	n--;
}
int main() {
	int n;
	printf("\nNhap so luong phan so:");
	scanf("%d", &n);
	PhanSo* mangPhanSo = (PhanSo*)malloc(n * sizeof(PhanSo));
	if (mangPhanSo == NULL) {
		printf("Khong the cap phat bo nho.\n");
		return 1;
	}
	NhapMangPS(mangPhanSo, n);
	XuatMangPS(mangPhanSo, n);
	timMax(mangPhanSo, n);
	timMin(mangPhanSo, n);
	xoaPhanTu(mangPhanSo, n, 1);
	XuatMangPS(mangPhanSo, n);
	return 0;
}