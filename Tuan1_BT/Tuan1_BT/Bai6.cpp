#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstdlib> 
#include<stdlib.h>
#define MAX_LEN 100
void nhapThongTin(char* hoten, char* phai, int* d, int* m, int* y) {
    printf("\nNhap ho va ten: ");
    fgets(hoten, MAX_LEN, stdin);
    size_t len_hoten = strlen(hoten);
    if (len_hoten > 0 && hoten[len_hoten - 1] == '\n') {
        hoten[len_hoten - 1] = '\0';
    }

    printf("\nNhap vao gioi tinh: ");
    fgets(phai, MAX_LEN, stdin);
    size_t len_phai = strlen(phai);
    if (len_phai > 0 && phai[len_phai - 1] == '\n') {
        phai[len_phai - 1] = '\0';
    }

    printf("\nNhap ngay thang nam (dd-mm-yyyy): ");
    scanf("%d %d %d", d, m, y);

}

void xuatThongTin(char* hoten, char* phai, int d, int m, int y) {
    printf("\nHo va ten: %s\n", hoten);
    printf("Gioi tinh: %s\n", phai);
    printf("Ngay sinh: %02d/%02d/%04d\n", d, m, y);
}
void tinhNghiHuu(char* hoten, char* phai, int d, int m, int y) {
    int namhientai = 2024;
    int k = 0;
    if (strcmp(phai, "Nam") || strcmp(phai, "Nu")) printf("\nLoi gioi tinh");;
    if (strcmp(phai, "Nam") && (namhientai - y > 62)) printf("\nLoi khong hop le");
    if ((namhientai - y < 18))  printf("\nLoi khong hop le");
    if (strcmp(phai, "Nu") && (namhientai - y > 60)) printf("\nLoi khong hop le");
    if (strcmp(phai, "Nam")) k = 62 - (2024 - y); else k = 60 - (2024 - y);
    int tuoinghihuu = k + 2024;
    xuatThongTin(hoten, phai, d, m, y);
    printf("\nTuoi nghi huu la: %d/%d", m, tuoinghihuu);
}
int main() {
    char hoten[MAX_LEN];
    char phai[MAX_LEN];
    int d, m, y;

    nhapThongTin(hoten, phai, &d, &m, &y);
    xuatThongTin(hoten, phai, d, m, y);
    tinhNghiHuu(hoten, phai, d, m, y);
    return 0;
}