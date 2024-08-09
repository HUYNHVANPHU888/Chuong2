/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_M 100
#define MAX_N 100

// Hàm kiểm tra số nguyên tố
bool laNguyenTo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra chữ số đầu tiên là số lẻ
bool chuSoDauLaLe(int n) {
    while (n >= 10) {
        n /= 10;
    }
    return (n % 2 != 0);
}

// Hàm kiểm tra số hoàn thiện
bool laSoHoanThien(int n) {
    if (n <= 0) return false;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return (sum == n);
}

// Hàm nhập ma trận
void nhapMaTran(int a[MAX_M][MAX_N], int* m, int* n) {
    printf("Nhap so dong va so cot: ");
    scanf("%d %d", m, n);
    printf("Nhap ma tran:\n");
    for (int i = 0; i < *m; i++) {
        for (int j = 0; j < *n; j++) {
            printf("Nhap phan tu a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX_M][MAX_N], int m, int n) {
    printf("Ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}

// Bài 1: Tính tổng các phần tử có chữ số đầu là chữ số lẻ
int tongChuSoDauLaLe(int a[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (chuSoDauLaLe(a[i][j])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Bài 2: Liệt kê các số hoàn thiện trong ma trận
void lietKeSoHoanThien(int a[MAX_M][MAX_N], int m, int n) {
    printf("Cac so hoan thien trong ma tran: ");
    bool found = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(a[i][j])) {
                printf("%d ", a[i][j]);
                found = true;
            }
        }
    }
    if (!found) {
        printf("Khong co so hoan thien.");
    }
    printf("\n");
}

// Bài 3: Tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int tongLonHonTriTuyetDoi(int a[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] > abs(a[i][j + 1])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Bài 4: Tính tổng giá trị trên dòng k của ma trận
int tongTrenDongK(int a[MAX_M][MAX_N], int n, int k) {
    int tong = 0;
    if (k >= 0 && k < MAX_M) {
        for (int j = 0; j < n; j++) {
            tong += a[k][j];
        }
    }
    return tong;
}

// Bài 5: Tính tổng các giá trị nằm trên biên của ma trận
int tongBienMaTran(int a[MAX_M][MAX_N], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        tong += a[i][0] + a[i][n - 1];
    }
    for (int j = 1; j < n - 1; j++) {
        tong += a[0][j] + a[m - 1][j];
    }
    return tong;
}

// Bài 6: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận
int demTanSuatX(int a[MAX_M][MAX_N], int m, int n, int x) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                dem++;
            }
        }
    }
    return dem;
}

// Bài 7: Đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
void demPhanTu(int a[MAX_M][MAX_N], int m, int n) {
    int chan = 0, le = 0, am = 0, duong = 0, nguyenTo = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                chan++;
            }
            else {
                le++;
            }
            if (a[i][j] < 0) {
                am++;
            }
            else if (a[i][j] > 0) {
                duong++;
            }
            if (laNguyenTo(abs(a[i][j]))) {
                nguyenTo++;
            }
        }
    }
    printf("So luong so chan: %d\n", chan);
    printf("So luong so le: %d\n", le);
    printf("So luong so am: %d\n", am);
    printf("So luong so duong: %d\n", duong);
    printf("So luong so nguyen to: %d\n", nguyenTo);
}

// Hàm hiển thị menu và thực hiện lựa chọn của người dùng
void menu() {
    int a[MAX_M][MAX_N];
    int m, n, k, x;
    int chon;

    nhapMaTran(a, &m, &n);
    xuatMaTran(a, m, n);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Tinh tong cac phan tu co chu so dau la chu so le\n");
        printf("2. Liet ke cac so hoan thien trong ma tran\n");
        printf("3. Tinh tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no\n");
        printf("4. Tinh tong gia tri tren dong k\n");
        printf("5. Tinh tong cac gia tri nam tren bien cua ma tran\n");
        printf("6. Dem tan suat x xuat hien trong ma tran\n");
        printf("7. Dem so luong so chan, so le, so am, so duong, so nguyen to\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
        case 1:
            printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoDauLaLe(a, m, n));
            break;

        case 2:
            lietKeSoHoanThien(a, m, n);
            break;

        case 3:
            printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau no: %d\n", tongLonHonTriTuyetDoi(a, m, n));
            break;

        case 4:
            printf("Nhap dong k: ");
            scanf("%d", &k);
            printf("Tong gia tri tren dong %d: %d\n", k, tongTrenDongK(a, n, k));
            break;

        case 5:
            printf("Tong cac gia tri nam tren bien cua ma tran: %d\n", tongBienMaTran(a, m, n));
            break;

        case 6:
            printf("Nhap gia tri x: ");
            scanf("%d", &x);
            printf("Tan suat x xuat hien trong ma tran: %d\n", demTanSuatX(a, m, n, x));
            break;

        case 7:
            demPhanTu(a, m, n);
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
    menu();
    return 0;
}
*/