#include "NhanVien2/CongTy.h"

int main()
{
    CongTy ct;

    ct.NhapDSNhanVien();
    ct.XuatDSNhanVien();

    cout << "Tong tien luong phai tra: " << ct.TongTienLuongPhaiTra() << endl;

    NhanVienSanXuat* nv_san_xuat = ct.TienLuongThapNhat();
    if (nv_san_xuat != nullptr)
    {
        cout << "Nhan vien san xuat co tien luong thap nhat: \n" << *nv_san_xuat << endl;
    }

    NhanVienVanPhong* nv_van_phong = ct.TuoiCaoNhat();
    if (nv_van_phong != nullptr)
    {
        cout << "Nhan vien van phong co tuoi cao nhat: \n" << *nv_van_phong << endl;
    }

    return 0;
}

