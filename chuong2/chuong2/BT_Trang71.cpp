/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MONHOC 5
#define MAX_SINHVIEN 100

// Cấu trúc môn học
typedef struct {
    char maMon[10];
    char tenMon[50];
    int soTinChi;
    float diem;
} MonHoc;

// Cấu trúc sinh viên
typedef struct {
    char maSinhVien[10];
    char hoTen[50];
    MonHoc danhSachMon[MAX_MONHOC];
    float diemTrungBinhTichLuy;
} SinhVien;

// Cấu trúc danh sách sinh viên
typedef struct {
    SinhVien danhSach[MAX_SINHVIEN];
    int soLuong;
} DanhSachSinhVien;

// Hàm nhập thông tin môn học
void nhapMonHoc(MonHoc* mon) {
    printf("Nhap ma mon: ");
    scanf("%s", mon->maMon);
    printf("Nhap ten mon: ");
    scanf(" %[^\n]", mon->tenMon);
    printf("Nhap so tin chi: ");
    scanf("%d", &mon->soTinChi);
    printf("Nhap diem: ");
    scanf("%f", &mon->diem);
}

// Hàm xuất thông tin môn học
void xuatMonHoc(MonHoc mon) {
    printf("Ma mon: %s\n", mon.maMon);
    printf("Ten mon: %s\n", mon.tenMon);
    printf("So tin chi: %d\n", mon.soTinChi);
    printf("Diem: %.2f\n", mon.diem);
}

// Hàm nhập thông tin sinh viên
void nhapSinhVien(SinhVien* sv) {
    printf("Nhap ma sinh vien: ");
    scanf("%s", sv->maSinhVien);
    printf("Nhap ho ten sinh vien: ");
    scanf(" %[^\n]", sv->hoTen);

    for (int i = 0; i < MAX_MONHOC; i++) {
        printf("Nhap thong tin mon hoc %d:\n", i + 1);
        nhapMonHoc(&sv->danhSachMon[i]);
    }
    // Tính điểm trung bình tích lũy
    float tongDiem = 0;
    int tongTinChi = 0;
    for (int i = 0; i < MAX_MONHOC; i++) {
        tongDiem += sv->danhSachMon[i].diem * sv->danhSachMon[i].soTinChi;
        tongTinChi += sv->danhSachMon[i].soTinChi;
    }
    sv->diemTrungBinhTichLuy = tongDiem / tongTinChi;
}

// Hàm xuất thông tin sinh viên
void xuatSinhVien(SinhVien sv) {
    printf("Ma sinh vien: %s\n", sv.maSinhVien);
    printf("Ho ten: %s\n", sv.hoTen);
    for (int i = 0; i < MAX_MONHOC; i++) {
        printf("Mon hoc %d:\n", i + 1);
        xuatMonHoc(sv.danhSachMon[i]);
    }
    printf("Diem trung binh tich luy: %.2f\n", sv.diemTrungBinhTichLuy);
}

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(DanhSachSinhVien* dssv) {
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &dssv->soLuong);
    for (int i = 0; i < dssv->soLuong; i++) {
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        nhapSinhVien(&dssv->danhSach[i]);
    }
}

// Hàm xuất danh sách sinh viên
void xuatDanhSachSinhVien(DanhSachSinhVien dssv) {
    for (int i = 0; i < dssv.soLuong; i++) {
        printf("Sinh vien %d:\n", i + 1);
        xuatSinhVien(dssv.danhSach[i]);
        printf("\n");
    }
}

// Hàm tìm sinh viên theo mã số
SinhVien* timSinhVien(DanhSachSinhVien* dssv, char* maSinhVien) {
    for (int i = 0; i < dssv->soLuong; i++) {
        if (strcmp(dssv->danhSach[i].maSinhVien, maSinhVien) == 0) {
            return &dssv->danhSach[i];
        }
    }
    return NULL;
}

// Hàm tìm sinh viên có điểm trung bình cao nhất
SinhVien* timSinhVienDiemCaoNhat(DanhSachSinhVien* dssv) {
    if (dssv->soLuong == 0) return NULL;
    SinhVien* svMax = &dssv->danhSach[0];
    for (int i = 1; i < dssv->soLuong; i++) {
        if (dssv->danhSach[i].diemTrungBinhTichLuy > svMax->diemTrungBinhTichLuy) {
            svMax = &dssv->danhSach[i];
        }
    }
    return svMax;
}

// Hàm thêm sinh viên vào danh sách
void themSinhVien(DanhSachSinhVien* dssv, SinhVien sv) {
    if (dssv->soLuong < MAX_SINHVIEN) {
        dssv->danhSach[dssv->soLuong++] = sv;
    }
    else {
        printf("Danh sach sinh vien da day.\n");
    }
}

// Hàm xóa sinh viên khỏi danh sách
void xoaSinhVien(DanhSachSinhVien* dssv, char* maSinhVien) {
    int index = -1;
    for (int i = 0; i < dssv->soLuong; i++) {
        if (strcmp(dssv->danhSach[i].maSinhVien, maSinhVien) == 0) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < dssv->soLuong - 1; i++) {
            dssv->danhSach[i] = dssv->danhSach[i + 1];
        }
        dssv->soLuong--;
    }
    else {
        printf("Sinh vien voi ma so %s khong ton tai.\n", maSinhVien);
    }
}

// Hàm sắp xếp sinh viên theo điểm trung bình (tăng dần)
void sapXepDiemTang(DanhSachSinhVien* dssv) {
    for (int i = 0; i < dssv->soLuong - 1; i++) {
        for (int j = i + 1; j < dssv->soLuong; j++) {
            if (dssv->danhSach[i].diemTrungBinhTichLuy > dssv->danhSach[j].diemTrungBinhTichLuy) {
                SinhVien temp = dssv->danhSach[i];
                dssv->danhSach[i] = dssv->danhSach[j];
                dssv->danhSach[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp sinh viên theo điểm trung bình (giảm dần)
void sapXepDiemGiam(DanhSachSinhVien* dssv) {
    for (int i = 0; i < dssv->soLuong - 1; i++) {
        for (int j = i + 1; j < dssv->soLuong; j++) {
            if (dssv->danhSach[i].diemTrungBinhTichLuy < dssv->danhSach[j].diemTrungBinhTichLuy) {
                SinhVien temp = dssv->danhSach[i];
                dssv->danhSach[i] = dssv->danhSach[j];
                dssv->danhSach[j] = temp;
            }
        }
    }
}

// Hàm xếp loại học tập của sinh viên
void xepLoaiHocTap(SinhVien sv) {
    if (sv.diemTrungBinhTichLuy >= 8.5) {
        printf("Xep loai: Gioi\n");
    }
    else if (sv.diemTrungBinhTichLuy >= 7.0) {
        printf("Xep loai: Khá\n");
    }
    else if (sv.diemTrungBinhTichLuy >= 5.5) {
        printf("Xep loai: Trung binh\n");
    }
    else {
        printf("Xep loai: Yeu\n");
    }
}

// Hàm thống kê số môn đậu rớt của sinh viên
void thongKeMonHoc(SinhVien sv) {
    int soMonDat = 0, soMonRot = 0;
    for (int i = 0; i < MAX_MONHOC; i++) {
        if (sv.danhSachMon[i].diem >= 5.0) {
            soMonDat++;
        }
        else {
            soMonRot++;
        }
    }
    printf("So mon dat: %d\n", soMonDat);
    printf("So mon rot: %d\n", soMonRot);
}

// Hàm hiển thị menu và thực hiện lựa chọn của người dùng
void menu() {
    DanhSachSinhVien dssv;
    dssv.soLuong = 0;
    int chon;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien theo ma so\n");
        printf("4. Tim sinh vien co diem trung binh cao nhat\n");
        printf("5. Them sinh vien vao danh sach\n");
        printf("6. Xoa sinh vien khoi danh sach\n");
        printf("7. Sap xep sinh vien theo diem trung binh (tang dan)\n");
        printf("8. Sap xep sinh vien theo diem trung binh (giam dan)\n");
        printf("9. Xep loai hoc tap\n");
        printf("10. Thong ke so mon dat, rot\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch (chon) {
        case 1:
            nhapDanhSachSinhVien(&dssv);
            break;

        case 2:
            xuatDanhSachSinhVien(dssv);
            break;

        case 3: {
            char maSinhVien[10];
            printf("Nhap ma sinh vien: ");
            scanf("%s", maSinhVien);
            SinhVien* sv = timSinhVien(&dssv, maSinhVien);
            if (sv != NULL) {
                xuatSinhVien(*sv);
            }
            else {
                printf("Sinh vien voi ma so %s khong ton tai.\n", maSinhVien);
            }
            break;
        }

        case 4: {
            SinhVien* svMax = timSinhVienDiemCaoNhat(&dssv);
            if (svMax != NULL) {
                printf("Sinh vien co diem trung binh cao nhat:\n");
                xuatSinhVien(*svMax);
            }
            else {
                printf("Danh sach sinh vien rong.\n");
            }
            break;
        }

        case 5: {
            SinhVien sv;
            printf("Nhap thong tin sinh vien moi:\n");
            nhapSinhVien(&sv);
            themSinhVien(&dssv, sv);
            break;
        }

        case 6: {
            char maSinhVien[10];
            printf("Nhap ma sinh vien can xoa: ");
            scanf("%s", maSinhVien);
            xoaSinhVien(&dssv, maSinhVien);
            break;
        }

        case 7:
            sapXepDiemTang(&dssv);
            printf("Danh sach sinh vien da duoc sap xep theo diem trung binh (tang dan).\n");
            break;

        case 8:
            sapXepDiemGiam(&dssv);
            printf("Danh sach sinh vien da duoc sap xep theo diem trung binh (giam dan).\n");
            break;

        case 9: {
            char maSinhVien[10];
            printf("Nhap ma sinh vien de xep loai: ");
            scanf("%s", maSinhVien);
            SinhVien* sv = timSinhVien(&dssv, maSinhVien);
            if (sv != NULL) {
                xepLoaiHocTap(*sv);
            }
            else {
                printf("Sinh vien voi ma so %s khong ton tai.\n", maSinhVien);
            }
            break;
        }

        case 10: {
            char maSinhVien[10];
            printf("Nhap ma sinh vien de thong ke: ");
            scanf("%s", maSinhVien);
            SinhVien* sv = timSinhVien(&dssv, maSinhVien);
            if (sv != NULL) {
                thongKeMonHoc(*sv);
            }
            else {
                printf("Sinh vien voi ma so %s khong ton tai.\n", maSinhVien);
            }
            break;
        }

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