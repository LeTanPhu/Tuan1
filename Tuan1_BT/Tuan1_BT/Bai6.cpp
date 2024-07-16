#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstdlib> 
#include<stdlib.h>
void nhapM1C_SoNguyen(int*& a, int& n)
{ //a và n là tham chiếu vì sau khi nhập giá trị, a và n cần giữ các giá trị mới nhận trong hàm
	n = 10;
	a = (int*)malloc(n * sizeof(int)); // cấp phát a co 10 phần tử
	for (int i = 0; i < n; i++)
		*(a + i) = rand() % 100;
}
void xuatM1C_SoNguyen(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		//printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, *(a + i), a + i);
		printf("\nPhan tu thu %d co gia tri %d va dia chi o nho la %x", i, a[i], a + i);
	}
}
void timPTMax(int* a, int n) {
	int max = 0;
	int* b;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= max)
		{
			max = a[i];
			b = &a[i];
		}
	}
	printf("\nPhan tu lon nhat la:%d va Dia chi cua no:%x\n", max, b);
}
void timLeMin(int* a, int n) {
	int minle = INT_MAX;
	int* c = NULL;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0) {
			if (a[i] < minle) {
				minle = a[i];
				c = &a[i];
			}
		}
	}
	if (c != NULL) {
		printf("\nDia chi cua phan tu le nho nhat trong mang la %x", c);
	}
	else {
		printf("\nKhong co so le trong mang.");
	}
}
void timChanMax(int* a, int n) {
	int maxchan = INT_MIN;
	int* d = NULL;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0) {
			if (a[i] > maxchan) {
				maxchan = a[i];
				d = &a[i];
			}
		}
	}
	if (d != NULL) {
		printf("\nDia chi cua phan tu chan lon nhat trong mang la %x", d);
	}
	else {
		printf("\nKhong co so chan trong mang.");
	}
}
void xoaPTBang0(int* a, int n) {
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 0) {
			for (int j = i; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			n--;
		}
	}
}
void themPT_VaoSauPTFirst(int* a, int n, int x) {
	for (int i = n; i > 1; i--)
	{
		a[i] = a[i - 1];
	}
	a[1] = x;
	n++;
}
int KT_SoChinhPhuong(double a) {
	double temp = sqrt(a);
	if (temp * temp == a) {
		return 1;
	}
	return 0;
}
void tong_SoChinhPhuong(int* a, int n) {
	int tong = 0;
	for (int i = 0; i < n; i++)
	{
		if (KT_SoChinhPhuong(a[i]) == 1) tong += a[i];
	}
	printf("\nTong cac so chinh phuong trong mang la:%d", tong);
}
void xuatSoCucDai(int* a, int n) {
	printf("\nCac so cuc dai la:");
	for (int i = 0; i < n; i++)
	{
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			printf("%d\t", a[i]);
	}
}
int main() {
	int* a, n = 0;
	nhapM1C_SoNguyen(a, n);
	xuatM1C_SoNguyen(a, n);
	printf("\nTim phan tu lon nhat");
	timPTMax(a, n);
	printf("\nTim dia chi phan tu le nho nhat");
	timLeMin(a, n);
	printf("\n");
	printf("\nTim dia chi phan tu chan lon nhat");
	timChanMax(a, n);
	printf("\n");
	printf("\nXoa phan tu bang 0");
	xoaPTBang0(a, n);
	xuatM1C_SoNguyen(a, n);
	printf("\n");
	printf("\nThem phan tu x vao sau phan tu dau tien");
	themPT_VaoSauPTFirst(a, n, 3);
	xuatM1C_SoNguyen(a, n);
	printf("\n");
	printf("\nTong cac so chinh phuong trong mang la");
	tong_SoChinhPhuong(a, n);
	printf("\n");
	printf("\nXuat cac so cuc dai");
	xuatSoCucDai(a, n);
}
