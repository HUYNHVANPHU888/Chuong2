/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<math.h>


void nhapMang(int a[], int n);
void xuatMang(int a[], int n);
int timMax(int a[], int n);
int timMin(int a[], int n);
int demChan(int a[], int n);
int demLe(int a[], int n);
int timKiemTuyenTinh(int a[], int n, int x);
int timKiemNhiPhan(int a[], int n, int x);
int demPhanTuX(int a[], int n, int x);
int demLonHonX(int a[], int n, int x);
int tongMang(int a[], int n);
bool laSoNguyenTo(int x);
bool laSoHoanThien(int x);
void xuatSoNguyenTo(int a[], int n);
void xuatSoHoanThien(int a[], int n);
void xuatViTriChan(int a[], int n);
void xuatViTriLe(int a[], int n);
void xuatMaxMinViTri(int a[], int n);
void ghepMang(int a[], int b[], int m, int c[], int n);

int main() {
    int n, m, x;
    int a[100], b[50], c[50];

    printf("Nhap so phan tu cua mang a: ");
    scanf("%d", &n);
    nhapMang(a, n);

    printf("Mang a: ");
    xuatMang(a, n);

    printf("Gia tri lon nhat trong mang a: %d\n", timMax(a, n));
    printf("Gia tri nho nhat trong mang a: %d\n", timMin(a, n));

    printf("So phan tu chan trong mang a: %d\n", demChan(a, n));
    printf("So phan tu le trong mang a: %d\n", demLe(a, n));

    printf("Nhap gia tri can tim kiem x: ");
    scanf("%d", &x);

    int viTri = timKiemTuyenTinh(a, n, x);
    if (viTri != -1) {
        printf("Tim thay gia tri %d o vi tri %d (tim kiem tuyen tinh)\n", x, viTri);
    }
    else {
        printf("Khong tim thay gia tri %d trong mang a (tim kiem tuyen tinh)\n", x);
    }

    printf("So phan tu co gia tri %d trong mang a: %d\n", x, demPhanTuX(a, n, x));
    printf("So phan tu lon hon %d trong mang a: %d\n", x, demLonHonX(a, n, x));
    printf("Tong cac phan tu trong mang a: %d\n", tongMang(a, n));

    printf("Cac so nguyen to trong mang a: ");
    xuatSoNguyenTo(a, n);

    printf("Cac so hoan thien trong mang a: ");
    xuatSoHoanThien(a, n);

    printf("Cac phan tu o vi tri chan trong mang a: ");
    xuatViTriChan(a, n);

    printf("Cac phan tu o vi tri le trong mang a: ");
    xuatViTriLe(a, n);

    xuatMaxMinViTri(a, n);

    printf("Nhap so phan tu cua mang b: ");
    scanf("%d", &m);
    nhapMang(b, m);

    printf("Nhap so phan tu cua mang c: ");
    scanf("%d", &n);
    nhapMang(c, n);

    printf("Ghep mang b va c thanh mang a (tang dan): ");
    int a_merged[100];
    ghepMang(a_merged, b, m, c, n);
    xuatMang(a_merged, m + n);

    return 0;
}

void nhapMang(int a[], int n) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int demChan(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int demLe(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i;
        }
    }
    return -1;
}

int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}

int demPhanTuX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

int demLonHonX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}

int tongMang(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

bool laSoNguyenTo(int x) {
    if (x < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

bool laSoHoanThien(int x) {
    int sum = 0;
    for (int i = 1; i <= x / 2; i++) {
        if (x % i == 0) {
            sum += i;
        }
    }
    return sum == x;
}

void xuatSoNguyenTo(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void xuatSoHoanThien(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (laSoHoanThien(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void xuatViTriChan(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void xuatViTriLe(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 != 0) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

void xuatMaxMinViTri(int a[], int n) {
    int max = a[0], min = a[0], maxPos = 0, minPos = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            maxPos = i;
        }
        if (a[i] < min) {
            min = a[i];
            minPos = i;
        }
    }
    printf("Gia tri lon nhat: %d o vi tri %d\n", max, maxPos);
    printf("Gia tri nho nhat: %d o vi tri %d\n", min, minPos);
}

void ghepMang(int a[], int b[], int m, int c[], int n) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (b[i] <= c[j]) {
            a[k++] = b[i++];
        }
        else {
            a[k++] = c[j++];
        }
    }
    while (i < m) {
        a[k++] = b[i++];
    }
    while (j < n) {
        a[k++] = c[j++];
    }
}*/