#pragma once 

#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien
{
    private:
        int luong_co_ban;
        int so_san_pham;
    public:
        NhanVienSanXuat(string = "", Date = Date(), int = 0, int = 0);

        int GetLuongCoBan() const;
        int GetSoSanPham() const;

        void SetLuongCoBan(int);
        void SetSoSanPham(int);

        void Nhap() override;
        void Xuat() const override;
        ll TienLuong() const override;

        
};


NhanVienSanXuat::NhanVienSanXuat(string ho_ten, Date ngay_sinh, int luong_co_ban, int so_san_pham)
    : NhanVien(ho_ten, ngay_sinh), luong_co_ban(luong_co_ban), so_san_pham(so_san_pham) {}

int NhanVienSanXuat::GetLuongCoBan() const { return luong_co_ban; }
int NhanVienSanXuat::GetSoSanPham() const { return so_san_pham; }

void NhanVienSanXuat::SetLuongCoBan(int luong_co_ban) { this->luong_co_ban = luong_co_ban; }
void NhanVienSanXuat::SetSoSanPham(int so_san_pham) { this->so_san_pham = so_san_pham; }

void NhanVienSanXuat::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap luong co ban: ";
    cin >> luong_co_ban;
    cout << "Nhap so san pham: ";
    cin >> so_san_pham;
}

void NhanVienSanXuat::Xuat() const
{
    NhanVien::Xuat();
    cout << "Luong co ban: " << luong_co_ban << endl;
    cout << "So san pham: " << so_san_pham << endl;
}

ll NhanVienSanXuat::TienLuong() const
{
    return luong_co_ban + so_san_pham * 5000; // Giả sử mỗi sản phẩm được trả 1000
}
