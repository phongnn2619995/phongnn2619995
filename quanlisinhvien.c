#include <stdio.h>
struct SinhVien {
    int mssv;
    char hoten[35];
    char ngaysinh[11];
};

int main() {
    struct SinhVien dssv[100];
    int n;
    printf("1. NHAP DANH SACH SINH VIEN\n");
    printf("Nhap so luong sinh vien N: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nNhap thong tin sinh vien thu %d:\n", i + 1);
        printf("- MSSV: ");
        scanf("%d", &dssv[i].mssv);
        printf("- Ho ten: ");
        scanf("%s", dssv[i].hoten); // Lưu ý: Nhập chuỗi đơn giản không có khoảng cách
        printf("- Ngay sinh (dd/mm/yyyy): ");
        scanf("%s", dssv[i].ngaysinh);
    }
    printf("\n\n4. DANH SACH SINH VIEN HIEN TAI:\n");
    printf("%-10s | %-20s | %-12s\n", "MSSV", "Ho Ten", "Ngay Sinh");
    printf("-----------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d | %-20s | %-12s\n", dssv[i].mssv, dssv[i].hoten, dssv[i].ngaysinh);
    }
    printf("\n\n2. TIM KIEM SINH VIEN\n");
    int maTim;
    printf("Nhap MSSV can tim: ");
    scanf("%d", &maTim);

    int timthay = 0;
    for (int i = 0; i < n; i++) {
        if (dssv[i].mssv == maTim) {
            printf("-> Da tim thay! Ho ten: %s, Ngay sinh: %s\n", dssv[i].hoten, dssv[i].ngaysinh);
            timthay = 1;
            break;
        }
    }
    if (!timthay) {
        printf("-> Khong tìm thay sinh vien co MSSV la %d\n", maTim);
    }
    printf("\n\n3. XOA SINH VIEN\n");
    int maXoa;
    printf("Nhap MSSV cua sinh vien muon xoa: ");
    scanf("%d", &maXoa);

    int vtXoa = -1;
    for (int i = 0; i < n; i++) {
        if (dssv[i].mssv == maXoa) {
            vtXoa = i;
            break;
        }
    }

    if (vtXoa == -1) {
        printf("-> Khong tim thay sinh vien de xoa!\n");
    } else {
        // Dịch mảng để xóa phần tử
        for (int i = vtXoa; i < n - 1; i++) {
            dssv[i] = dssv[i + 1];
        }
        n--; // Giảm số lượng sinh viên đi 1
        printf("-> Da xoa thanh cong!\n");
        printf("\nDANH SACH SAU KHI XOA:\n");
        printf("%-10s | %-20s | %-12s\n", "MSSV", "Ho Ten", "Ngay Sinh");
        printf("-----------------------------------------\n");
        for (int i = 0; i < n; i++) {
            printf("%-10d | %-20s | %-12s\n", dssv[i].mssv, dssv[i].hoten, dssv[i].ngaysinh);
        }
    }

    return 0;
}