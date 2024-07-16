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
void xuatSoCucTieu(int* a, int n) {
	printf("\nCac so cuc tieu la:");
	for (int i = 0; i < n; i++)
	{
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
			printf("%d\t", a[i]);
	}
}
void xoaPTTaiK(int* a, int n, int vitri) {
	if (vitri < 0 || vitri>n) {
		printf("\nKhong co phan tu!");
	}
	n--;
	for (int i = vitri; i < n; i++)
	{
		a[i] = a[i + 1];
	}
}
void themPTTaiK(int* a, int n, int vitri, int k) {
	if (vitri < 0 || vitri>n) {
		printf("\nKhong co phan tu!");
	}
	n++;
	for (int i = n; i > vitri; i--)
	{
		a[i] = a[i - 1];
	}
	a[vitri] = k;
}
void ChuyenChanLe(int* a, int n) {
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		while (left < right && a[left] % 2 == 0) {
			left++;
		}
		while (left < right && a[right] % 2 != 0)
		{
			right--;
		}
		if (left < right) {
			int temp = a[left];
			a[left] = a[right];
			a[right] = temp;
			left++;
			right--;
		}
	}
}
int KT_ChanLeXenKe(int* a, int n) {
	for (int i = 0; i < n; i++)
	{
		if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) return 0;
	}
	return 1;
}
int main() {
	int* a, n;
	nhapM1C_SoNguyen(a, n);
	xuatM1C_SoNguyen(a, n);
	printf("\n");
	xuatSoCucTieu(a, n);
	printf("\n");
	printf("\nXoa phan tu so 3");
	xoaPTTaiK(a, n, 3);
	xuatM1C_SoNguyen(a, n);
	printf("\n");
	printf("\nThem phan tu 10 tai vi tri 4");
	themPTTaiK(a, n, 4, 10);
	xuatM1C_SoNguyen(a, n);
	printf("\n");
	printf("\nSap xep chan len dau le xuong duoi");
	ChuyenChanLe(a, n);
	xuatM1C_SoNguyen(a, n);
	printf("\n");
	if (KT_ChanLeXenKe(a, n) == 1) printf("\nMang co chua chan le xen ke"); else printf("\nMang ko chua chan le xen ke");
}