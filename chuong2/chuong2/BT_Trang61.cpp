/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Hàm kiểm tra số nguyên tố
bool laNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có chứa toàn bộ số nguyên tố không
bool laMangToanNguyenTo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (!laNguyenTo(a[i])) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có đối xứng không
bool laMangDoiXung(int a[], int n) {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có tăng dần không
bool laMangTangDan(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có giảm dần không
bool laMangGiamDan(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có tăng dần, giảm dần, hoặc không tăng không giảm
void kiemTraMang(int a[], int n) {
    if (laMangToanNguyenTo(a, n)) {
        printf("Mang chua toan bo so nguyen to.\n");
    }
    else {
        printf("Mang khong chua toan bo so nguyen to.\n");
    }

    if (laMangDoiXung(a, n)) {
        printf("Mang la mang doi xung.\n");
    }
    else {
        printf("Mang khong la mang doi xung.\n");
    }

    if (laMangTangDan(a, n)) {
        printf("Mang la mang tang dan.\n");
    }
    else if (laMangGiamDan(a, n)) {
        printf("Mang la mang giam dan.\n");
    }
    else {
        printf("Mang khong tang dan, khong giam dan.\n");
    }
}

// Hàm hiển thị menu và thực hiện lựa chọn của người dùng
void menu(int a[], int n) {
    int chon;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Kiem tra mang toan so nguyen to\n");
        printf("2. Kiem tra mang doi xung\n");
        printf("3. Kiem tra mang tang dan, giam dan, hoac khong tang khong giam\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
        case 1:
            if (laMangToanNguyenTo(a, n)) {
                printf("Mang chua toan bo so nguyen to.\n");
            }
            else {
                printf("Mang khong chua toan bo so nguyen to.\n");
            }
            break;

        case 2:
            if (laMangDoiXung(a, n)) {
                printf("Mang la mang doi xung.\n");
            }
            else {
                printf("Mang khong la mang doi xung.\n");
            }
            break;

        case 3:
            kiemTraMang(a, n);
            break;

        case 0:
            printf("Thoat chuong trinh.\n");
            break;

        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (chon != 0);
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    // Cấp phát động cho mảng
    int* a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i);
        scanf("%d", &a[i]);
    }

    menu(a, n);

    // Giải phóng bộ nhớ
    free(a);
    return 0;
}
*/