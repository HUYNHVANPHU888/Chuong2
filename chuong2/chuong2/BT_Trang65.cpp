/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// Cấu trúc phân số
typedef struct {
    int tu;  // Tử số
    int mau; // Mẫu số
} PhanSo;

// Hàm kiểm tra mẫu số khác 0
bool kiemTraMauKhac0(int mau) {
    return mau != 0;
}

// Hàm nhập phân số
void nhapPhanSo(PhanSo* ps) {
    do {
        printf("Nhap tu so: ");
        scanf("%d", &ps->tu);
        printf("Nhap mau so: ");
        scanf("%d", &ps->mau);
        if (!kiemTraMauKhac0(ps->mau)) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (!kiemTraMauKhac0(ps->mau));
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo ps) {
    printf("%d/%d\n", ps.tu, ps.mau);
}

// Hàm tính ước số chung lớn nhất
int ucln(int a, int b) {
    a = a < 0 ? -a : a;
    b = b < 0 ? -b : b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tối giản phân số
void toiGianPhanSo(PhanSo* ps) {
    int uclnVal = ucln(ps->tu, ps->mau);
    ps->tu /= uclnVal;
    ps->mau /= uclnVal;
}

// Hàm tính tổng của hai phân số
PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

// Hàm tính hiệu của hai phân số
PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

// Hàm tính tích của hai phân số
PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.tu;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

// Hàm tính thương của hai phân số
PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    if (kiemTraMauKhac0(ps2.tu)) {
        ketQua.tu = ps1.tu * ps2.mau;
        ketQua.mau = ps1.mau * ps2.tu;
        toiGianPhanSo(&ketQua);
    }
    else {
        printf("Khong the chia cho 0.\n");
        ketQua.tu = 0;
        ketQua.mau = 1; // Đặt mặc định 0/1 để tránh lỗi
    }
    return ketQua;
}

// Hàm hiển thị menu và thực hiện lựa chọn của người dùng
void menu() {
    PhanSo ps1, ps2;
    int chon;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap hai phan so\n");
        printf("2. Tinh tong hai phan so\n");
        printf("3. Tinh hieu hai phan so\n");
        printf("4. Tinh tich hai phan so\n");
        printf("5. Tinh thuong hai phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
        case 1:
            printf("Nhap vao phan so 1:\n");
            nhapPhanSo(&ps1);
            printf("Nhap vao phan so 2:\n");
            nhapPhanSo(&ps2);
            break;

        case 2:
            printf("Tong hai phan so:\n");
            xuatPhanSo(tongPhanSo(ps1, ps2));
            break;

        case 3:
            printf("Hieu hai phan so:\n");
            xuatPhanSo(hieuPhanSo(ps1, ps2));
            break;

        case 4:
            printf("Tich hai phan so:\n");
            xuatPhanSo(tichPhanSo(ps1, ps2));
            break;

        case 5:
            printf("Thuong hai phan so:\n");
            xuatPhanSo(thuongPhanSo(ps1, ps2));
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