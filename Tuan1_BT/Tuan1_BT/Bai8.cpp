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
void XuatPSMauhonTu(PhanSo* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i].mau > arr[i].tu) {
			Xuat1PS(arr[i]);
		}
	}
}
int DemPS(PhanSo* arr, int n) {
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i].tu % 2 == 0 && arr[i].mau % 2 == 0)
			dem++;
	}
	return dem;
}
int TimUCLL(int a, int b) {
	if (a == 0 && b == 0) return a + b;
	while (a != b)
	{
		if (a > b) a -= b; else
		{
			b -= a;
		}
	}
	return a;
}
void RutGonPS(PhanSo* arr, int n) {
	for (int i = 0; i < n; i++)
	{
		int ucln = TimUCLL(arr[i].tu, arr[i].mau);
		arr[i].tu /= ucln;
		arr[i].mau /= ucln;
	}
}
float TichcacPS(PhanSo* arr, int n) {
	float tongtu = 1;
	float tongmau = 1;
	for (int i = 0; i < n; i++)
	{
		tongtu *= arr[i].tu;
		tongmau *= arr[i].mau;
	}
	return tongtu / tongmau;
}
void timMax(PhanSo* arr, int n) {
	float max = 0;
	int tumax, maumax;
	for (int i = 0; i < n; i++)
	{
		float x = (float)arr[i].tu / arr[i].mau;
		if (max < x) {
			x = max;
			tumax = arr[i].tu;
			maumax = arr[i].mau;
		}
	}
	printf("\nPhan so lon nhat:%d/%d", tumax, maumax);
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
	printf("\nDanh sach cac phan so mau > tu");
	XuatPSMauhonTu(mangPhanSo, n);
	printf("\nDem phan so co tu va mau chan:%d", DemPS(mangPhanSo, n));
	printf("\nDanh sach rut gon phan so");
	RutGonPS(mangPhanSo, n);
	XuatMangPS(mangPhanSo, n);
	printf("\nTich cac phan so trong mang:%.2f", TichcacPS(mangPhanSo, n));
	timMax(mangPhanSo, n);
	return 0;
}