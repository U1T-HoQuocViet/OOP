#include "SinhVien/TruongDH.h"

int main() 
{
    TruongDH qlsv;

    qlsv.NhapDSSinhVien();
    qlsv.XuatDSSinhVien();

    // cout << "Danh sach sinh vien tot nghiep:\n";
    qlsv.XuatSVTotNghiep();

    // cout << "Danh sach sinh vien khong du dieu kien tot nghiep:\n";
    qlsv.XuatSVKhongDuDieuKienTotNghiep();

    SVDaiHoc* sv_dai_hoc = qlsv.SinhVienDaiHocCoDiemTBCaoNhat();
    if (sv_dai_hoc != nullptr) {
        cout << "Sinh vien dai hoc co diem trung binh cao nhat: " << *sv_dai_hoc << endl;
    }

    SVCaoDang* sv_cao_dang = qlsv.SinhVienCaoDangCoDiemTBCaoNhat();
    if (sv_cao_dang != nullptr) {
        cout << "Sinh vien cao dang co diem trung binh cao nhat: " << *sv_cao_dang << endl;
    }

    qlsv.SVKhongDuDKTotNghiepTungLoai();

    return 0;
}