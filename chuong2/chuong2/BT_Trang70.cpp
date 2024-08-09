/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SINH_VIEN 50
#define DIEM_TIEU_LUAN 30
#define DIEM_THI 70
#define DIEM_QUA_TINH 4

typedef struct {
    int so_thu_tu;
    char ma_so[10];
    char ho_ten[100];
    float diem_tieu_luan;
    float diem_thi;
    float diem_tong_ket;
} SinhVien;

// Hàm nhập danh sách sinh viên từ bàn phím
void nhap_danh_sach(SinhVien arr[], int* n) {
    printf("Nhap so luong sinh vien (toi da %d): ", MAX_SINH_VIEN);
    scanf_s("%d", n);
    if (*n > MAX_SINH_VIEN) {
        printf("So luong sinh vien vuot qua gioi han, gan max = %d\n", MAX_SINH_VIEN);
        *n = MAX_SINH_VIEN;
    }

    for (int i = 0; i < *n; ++i) {
        arr[i].so_thu_tu = i + 1;
        printf("Nhap ma so sinh vien %d: ", i + 1);
        scanf_s("%s", arr[i].ma_so, (unsigned)_countof(arr[i].ma_so));
        printf("Nhap ho ten sinh vien %d: ", i + 1);
        scanf_s(" %[^\n]%*c", arr[i].ho_ten, (unsigned)_countof(arr[i].ho_ten));
        printf("Nhap diem tieu luan sinh vien %d: ", i + 1);
        scanf_s("%f", &arr[i].diem_tieu_luan);
        printf("Nhap diem thi sinh vien %d: ", i + 1);
        scanf_s("%f", &arr[i].diem_thi);

        // Tính điểm tổng kết
        arr[i].diem_tong_ket = (DIEM_TIEU_LUAN * arr[i].diem_tieu_luan + DIEM_THI * arr[i].diem_thi) / 100;
    }
}

// Hàm xuất danh sách sinh viên
void xuat_danh_sach(SinhVien arr[], int n) {
    printf("\nDanh sach sinh vien:\n");
    for (int i = 0; i < n; ++i) {
        printf("So thu tu: %d\n", arr[i].so_thu_tu);
        printf("Ma so: %s\n", arr[i].ma_so);
        printf("Ho ten: %s\n", arr[i].ho_ten);
        printf("Diem tieu luan: %.2f\n", arr[i].diem_tieu_luan);
        printf("Diem thi: %.2f\n", arr[i].diem_thi);
        printf("Diem tong ket: %.2f\n", arr[i].diem_tong_ket);
        printf("------------------------\n");
    }
}

// Hàm tìm sinh viên có điểm tổng kết cao nhất
SinhVien tim_sinh_vien_lon_nhat(SinhVien arr[], int n) {
    SinhVien max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i].diem_tong_ket > max.diem_tong_ket) {
            max = arr[i];
        }
    }
    return max;
}

// Hàm tìm sinh viên có điểm tổng kết thấp nhất
SinhVien tim_sinh_vien_nho_nhat(SinhVien arr[], int n) {
    SinhVien min = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i].diem_tong_ket < min.diem_tong_ket) {
            min = arr[i];
        }
    }
    return min;
}

// Hàm đếm số sinh viên đạt và không đạt
void dem_sinh_vien(SinhVien arr[], int n) {
    int dat = 0, khong_dat = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i].diem_tong_ket >= 5.0) {  // Giả sử điểm đạt >= 5.0
            dat++;
        }
        else {
            khong_dat++;
        }
    }
    printf("So sinh vien dat: %d\n", dat);
    printf("So sinh vien khong dat: %d\n", khong_dat);
}

// Hàm qui đổi điểm từ hệ 10 sang hệ 4
float qui_doi_diem(float diem_10) {
    if (diem_10 >= 8.5) return 4.0;
    if (diem_10 >= 7.0) return 3.5;
    if (diem_10 >= 5.5) return 3.0;
    if (diem_10 >= 4.0) return 2.0;
    return 1.0;
}

// Hàm qui đổi điểm cho toàn bộ sinh viên
void qui_doi_diem_sinh_vien(SinhVien arr[], int n) {
    for (int i = 0; i < n; ++i) {
        float diem_he_4 = qui_doi_diem(arr[i].diem_tong_ket);
        printf("Sinh vien %d: Diem he 4: %.2f\n", arr[i].so_thu_tu, diem_he_4);
    }
}

// Hàm sắp xếp danh sách sinh viên theo điểm tổng kết tăng dần
void sap_xep_tang(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i].diem_tong_ket > arr[j].diem_tong_ket) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp danh sách sinh viên theo điểm tổng kết giảm dần
void sap_xep_giam(SinhVien arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i].diem_tong_ket < arr[j].diem_tong_ket) {
                SinhVien temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm tính điểm trung bình của tất cả các sinh viên
float tinh_diem_trung_binh(SinhVien arr[], int n) {
    float tong = 0;
    for (int i = 0; i < n; ++i) {
        tong += arr[i].diem_tong_ket;
    }
    return (n > 0) ? tong / n : 0;
}

// Hàm ghi dữ liệu vào file
void ghi_du_lieu_vao_file(SinhVien arr[], int n, const char* filename) {
    FILE* file;
    fopen_s(&file, filename, "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        fprintf(file, "So thu tu: %d\n", arr[i].so_thu_tu);
        fprintf(file, "Ma so: %s\n", arr[i].ma_so);
        fprintf(file, "Ho ten: %s\n", arr[i].ho_ten);
        fprintf(file, "Diem tieu luan: %.2f\n", arr[i].diem_tieu_luan);
        fprintf(file, "Diem thi: %.2f\n", arr[i].diem_thi);
        fprintf(file, "Diem tong ket: %.2f\n", arr[i].diem_tong_ket);
        fprintf(file, "------------------------\n");
    }
    fclose(file);
}

// Hàm đọc dữ liệu từ file
void doc_du_lieu_tu_file(SinhVien arr[], int* n, const char* filename) {
    FILE* file;
    fopen_s(&file, filename, "r");
    if (file == NULL) {
        printf("Khong the mo file de doc.\n");
        return;
    }
    int i = 0;
    while (fscanf_s(file, "So thu tu: %d\n", &arr[i].so_thu_tu) != EOF &&
        fscanf_s(file, "Ma so: %s\n", arr[i].ma_so, (unsigned)_countof(arr[i].ma_so)) == 1 &&
        fscanf_s(file, "Ho ten: %[^\n]\n", arr[i].ho_ten, (unsigned)_countof(arr[i].ho_ten)) == 1 &&
        fscanf_s(file, "Diem tieu luan: %f\n", &arr[i].diem_tieu_luan) == 1 &&
        fscanf_s(file, "Diem thi: %f\n", &arr[i].diem_thi) == 1 &&
        fscanf_s(file, "Diem tong ket: %f\n", &arr[i].diem_tong_ket) == 1) {
        i++;
    }
    *n = i;
    fclose(file);
}

// Hàm chính của chương trình
int main() {
    SinhVien ds_sinh_vien[MAX_SINH_VIEN];
    int n = 0;
    int lua_chon;

    do {
        printf("\n=== MENU ===\n");
        printf("1. Nhap danh sach sinh vien\n");
        printf("2. Xuat danh sach sinh vien\n");
        printf("3. Tim sinh vien co diem tong ket cao nhat\n");
        printf("4. Tim sinh vien co diem tong ket thap nhat\n");
        printf("5. Dem so sinh vien dat va khong dat\n");
        printf("6. Qui doi diem he 10 sang he 4\n");
        printf("7. Sap xep danh sach sinh vien theo diem tong ket\n");
        printf("8. Tinh diem trung binh cua tat ca sinh vien\n");
        printf("9. Ghi du lieu vao file\n");
        printf("10. Doc du lieu tu file\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf_s("%d", &lua_chon);

        switch (lua_chon) {
        case 1:
            nhap_danh_sach(ds_sinh_vien, &n);
            break;
        case 2:
            xuat_danh_sach(ds_sinh_vien, n);
            break;
        case 3:
        {
            SinhVien max = tim_sinh_vien_lon_nhat(ds_sinh_vien, n);
            printf("Sinh vien co diem tong ket cao nhat:\n");
            printf("So thu tu: %d\n", max.so_thu_tu);
            printf("Ma so: %s\n", max.ma_so);
            printf("Ho ten: %s\n", max.ho_ten);
            printf("Diem tong ket: %.2f\n", max.diem_tong_ket);
        }
        break;
        case 4:
        {
            SinhVien min = tim_sinh_vien_nho_nhat(ds_sinh_vien, n);
            printf("Sinh vien co diem tong ket thap nhat:\n");
            printf("So thu tu: %d\n", min.so_thu_tu);
            printf("Ma so: %s\n", min.ma_so);
            printf("Ho ten: %s\n", min.ho_ten);
            printf("Diem tong ket: %.2f\n", min.diem_tong_ket);
        }
        break;
        case 5:
            dem_sinh_vien(ds_sinh_vien, n);
            break;
        case 6:
            qui_doi_diem_sinh_vien(ds_sinh_vien, n);
            break;
        case 7:
        {
            int lua_chon_sap_xep;
            printf("1. Sap xep tang dan\n");
            printf("2. Sap xep giam dan\n");
            printf("Nhap lua chon sap xep: ");
            scanf_s("%d", &lua_chon_sap_xep);
            if (lua_chon_sap_xep == 1) {
                sap_xep_tang(ds_sinh_vien, n);
            }
            else if (lua_chon_sap_xep == 2) {
                sap_xep_giam(ds_sinh_vien, n);
            }
            xuat_danh_sach(ds_sinh_vien, n);
        }
        break;
        case 8:
        {
            float diem_trung_binh = tinh_diem_trung_binh(ds_sinh_vien, n);
            printf("Diem trung binh cua tat ca sinh vien: %.2f\n", diem_trung_binh);
        }
        break;
        case 9:
            ghi_du_lieu_vao_file(ds_sinh_vien, n, "sinhvien.txt");
            break;
        case 10:
            doc_du_lieu_tu_file(ds_sinh_vien, &n, "sinhvien.txt");
            xuat_danh_sach(ds_sinh_vien, n);
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            break;
        }
    } while (lua_chon != 0);

    return 0;
}*/
