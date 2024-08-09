/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Hàm kiểm tra số nguyên tố
bool laNguyenTo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đếm số lượng số nguyên tố trong mảng
int demSoNguyenTo(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (laNguyenTo(a[i])) count++;
    }
    return count;
}

// Hàm kiểm tra tất cả các chữ số của số có phải là số lẻ không
bool tatCaSoLe(int n) {
    if (n == 0) return false;
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) return false;
        n /= 10;
    }
    return true;
}

// Hàm xuất các phần tử mà từng chữ số của nó là số lẻ
void xuatTatCaSoLe(int a[], int n) {
    printf("Cac phan tu ma tung chu so cua no la so le: ");
    for (int i = 0; i < n; i++) {
        if (tatCaSoLe(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

// Hàm tìm vị trí số lớn nhất cuối cùng
int viTriMaxCuoi(int a[], int n) {
    int max = a[0];
    int viTri = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= max) {
            max = a[i];
            viTri = i;
        }
    }
    return viTri;
}

// Hàm kiểm tra mảng có toàn số chẵn không
bool laMangToanChan(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có phải là dãy số chẵn lẻ xen kẻ không
bool laDayChanLeXenKe(int a[], int n) {
    if (n < 2) return true; // Mảng có ít hơn 2 phần tử luôn đúng

    bool chan = (a[0] % 2 == 0);
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2 == 0) == chan) return false;
        chan = !chan;
    }
    return true;
}

// Hàm hiển thị menu và thực hiện lựa chọn của người dùng
void menu(int a[], int n) {
    int chon;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Dem so phan tu la so nguyen to\n");
        printf("2. Xuat cac phan tu ma tung chu so cua no la so le\n");
        printf("3. Tim vi tri so lon nhat cuoi cung\n");
        printf("4. Kiem tra mang toan so chan\n");
        printf("5. Kiem tra mang la day so chan le xen ke\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
        case 1:
            printf("So luong phan tu la so nguyen to: %d\n", demSoNguyenTo(a, n));
            break;

        case 2:
            xuatTatCaSoLe(a, n);
            break;

        case 3: {
            int viTriMax = viTriMaxCuoi(a, n);
            printf("Vi tri so lon nhat cuoi cung: %d (Gia tri: %d)\n", viTriMax, a[viTriMax]);
            break;
        }

        case 4:
            if (laMangToanChan(a, n)) {
                printf("Mang toan so chan.\n");
            }
            else {
                printf("Mang khong toan so chan.\n");
            }
            break;

        case 5:
            if (laDayChanLeXenKe(a, n)) {
                printf("Mang la day so chan le xen ke.\n");
            }
            else {
                printf("Mang khong phai day so chan le xen ke.\n");
            }
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