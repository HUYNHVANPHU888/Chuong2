#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// Hàm hoán đổi 2 giá trị kiểu int
void swapInt(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm hoán đổi 2 giá trị kiểu float
void swapFloat(float* a, float* b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm hoán đổi 2 giá trị kiểu char
void swapChar(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm hoán đổi 2 chuỗi ký tự
void swapString(const char** a, const char** b) {
    const char* temp = *a;
    *a = *b;
    *b = temp;
}

// Sắp xếp tăng dần kiểu int
void sapXepTangInt(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swapInt(&a[i], &a[j]);
            }
        }
    }
}

// Sắp xếp giảm dần kiểu int
void sapXepGiamInt(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swapInt(&a[i], &a[j]);
            }
        }
    }
}

// Sắp xếp tăng dần kiểu float
void sapXepTangFloat(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swapFloat(&a[i], &a[j]);
            }
        }
    }
}

// Sắp xếp giảm dần kiểu float
void sapXepGiamFloat(float a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swapFloat(&a[i], &a[j]);
            }
        }
    }
}

// Sắp xếp tăng dần kiểu char
void sapXepTangChar(char a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swapChar(&a[i], &a[j]);
            }
        }
    }
}

// Sắp xếp giảm dần kiểu char
void sapXepGiamChar(char a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                swapChar(&a[i], &a[j]);
            }
        }
    }
}

// Sắp xếp tăng dần kiểu chuỗi ký tự
void sapXepTangString(const char* a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i], a[j]) > 0) {
                swapString(&a[i], &a[j]);
            }
        }
    }
}

// Sắp xếp giảm dần kiểu chuỗi ký tự
void sapXepGiamString(const char* a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(a[i], a[j]) < 0) {
                swapString(&a[i], &a[j]);
            }
        }
    }
}

int main() {
    // Ví dụ sử dụng các hàm
    int arrInt[] = { 3, 1, 4, 1, 5, 9 };
    float arrFloat[] = { 3.14, 1.59, 2.65, 3.58 };
    char arrChar[] = { 'd', 'a', 'c', 'b' };
    const char* arrString[] = { "banana", "apple", "cherry", "date" };

    int nInt = sizeof(arrInt) / sizeof(arrInt[0]);
    int nFloat = sizeof(arrFloat) / sizeof(arrFloat[0]);
    int nChar = sizeof(arrChar) / sizeof(arrChar[0]);
    int nString = sizeof(arrString) / sizeof(arrString[0]);

    sapXepTangInt(arrInt, nInt);
      printf("Mang so nguyen sap xep tang: ");
    for (int i = 0; i < nInt; i++) printf("%d ", arrInt[i]);
    printf("\n");

    sapXepGiamFloat(arrFloat, nFloat);
    printf("Mang so thuc sap xep giam: ");
    for (int i = 0; i < nFloat; i++) printf("%.2f ", arrFloat[i]);
    printf("\n");

    sapXepTangChar(arrChar, nChar);
    printf("Mang ky tu sap xep tang: ");
    for (int i = 0; i < nChar; i++) printf("%c ", arrChar[i]);
    printf("\n");

    sapXepGiamString(arrString, nString);
    printf("Mang chuoi ky tu sap xep giam: ");
    for (int i = 0; i < nString; i++) printf("%s ", arrString[i]);
    printf("\n");

    return 0;
}
