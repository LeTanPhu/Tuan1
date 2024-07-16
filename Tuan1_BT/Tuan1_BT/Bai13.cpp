#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstdlib> 
#include<stdlib.h>
void nhapM1C_SoNguyen1(int*& a, int& n)
{ //a và n là tham chiếu vì sau khi nhập giá trị, a và n cần giữ các giá trị mới nhận trong hàm
	n = 10;
	a = (int*)malloc(n * sizeof(int)); // cấp phát a co 10 phần tử
	for (int i = 0; i < n; i++)
		*(a + i) = rand() % 1000;
}
void nhapM1C_SoNguyen2(int*& a, int& n)
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
void TinhKQThuong(int* a, int* b, int n1, int n2) {
	try
	{
		if (n1 != n2) throw 101;
		else
		{
			for (int i = 0; i < n1; i++)
			{
				if (b[i] == 0) throw 102;
				else
				{
					float kq = (float)a[i] / b[i];
					printf("\nKet qua cua a[%d] / b[%d] = %.2f", i, i, kq);
				}
			}
		}
	}
	catch (int loi)
	{
		if (loi == 101) printf("\nMang khong cung kich thuoc!");
		else
		{
			if (loi == 102) printf("\nKhong the chia cho 0!");
		}
	}

}
int main() {
	int* a, * b, n1, n2;
	nhapM1C_SoNguyen1(a, n1);
	xuatM1C_SoNguyen(a, n1);
	printf("\n");
	nhapM1C_SoNguyen2(b, n2);
	xuatM1C_SoNguyen(b, n2);
	printf("\n");
	TinhKQThuong(a, b, n1, n2);
}