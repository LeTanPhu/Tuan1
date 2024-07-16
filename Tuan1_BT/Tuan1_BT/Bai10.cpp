#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<cstdlib> 
#include<stdlib.h>
void nhapChuoi(char* str, int maxLen) {
    printf("\nNhap chuoi can tinh: ");
    if (fgets(str, maxLen, stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
        }
    }
    else {
        printf("Loi khi nhap chuoi.\n");
    }
}
void xuatChuoi(char* str, int maxLen) {
    printf("Chuoi da nhap: %s\n", str);
}
void chuyenDoi(char* str) {
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] -= 32;
    }
    for (int i = 1; i < strlen(str); i++)
    {
        if (str[i - 1] == ' ' && str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}
int main() {
    int maxLen = 100;
    char* str = (char*)malloc(maxLen * sizeof(char));
    if (str == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }
    nhapChuoi(str, maxLen);
    xuatChuoi(str, maxLen);
    chuyenDoi(str);
    printf("\nChuoi sau khi chuyen doi:%s", str);
    printf("\nChuyen doi chuoi thanh chu hoa: %s", strupr(str));
    return 0;
}