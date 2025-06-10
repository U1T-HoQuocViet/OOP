#include "NhanVien/CongTy.h"

int main() 
{
    CongTyPhanMem cong_ty;
    cong_ty.NhapDanhSachNhanVien();
    cong_ty.XuatDanhSachNhanVien();
    cout << "Luong trung binh: " << cong_ty.LuongTrungBinh() << endl;
    cong_ty.DanhSachNhanVienCoLuongThapHonTrungBinh();

    NhanVien* nv_cao_nhat = cong_ty.NhanVienCoLuongCaoNhat();
    if (nv_cao_nhat) {
        cout << "Nhan vien co luong cao nhat: " << endl;
        nv_cao_nhat->Xuat();
        cout << "-> Luong: " << nv_cao_nhat->TinhLuong() << endl;
    } else {
        cout << "Khong co nhan vien nao." << endl;
    }

    NhanVien* nv_thap_nhat = cong_ty.NhanVienCoLuongThapNhat();
    if (nv_thap_nhat) {
        cout << "Nhan vien co luong thap nhat: " << endl;
        nv_thap_nhat->Xuat();
        cout << "-> Luong: " << nv_thap_nhat->TinhLuong() << endl;
    } else {
        cout << "Khong co nhan vien nao." << endl;
    }

    LapTrinhVien* lap_trinh_cao_nhat = cong_ty.NhanVienLapTrinhCoLuongCaoNhat();
    if (lap_trinh_cao_nhat) {
        cout << "Lap trinh vien co luong cao nhat: " << endl;
        lap_trinh_cao_nhat->Xuat();
        cout << "-> Luong: " << lap_trinh_cao_nhat->TinhLuong() << endl;
    } else {
        cout << "Khong co lap trinh vien nao." << endl;
    }

    KiemChungVien* kiem_chung_thap_nhat = cong_ty.NhanVienKiemChungCoLuongThapNhat();
    if (kiem_chung_thap_nhat) {
        cout << "Kiem chung vien co luong thap nhat: " << endl;
        kiem_chung_thap_nhat->Xuat();
        cout << "-> Luong: " << kiem_chung_thap_nhat->TinhLuong() << endl;
    } else {
        cout << "Khong co kiem chung vien nao." << endl;
    }
}