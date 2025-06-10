#pragma once 

#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien
{
    private:
        int so_ngay_lam;
    public:
        NhanVienVanPhong(string = "", Date = Date(), int = 0);

        int GetSoNgayLam() const;

        void SetSoNgayLam(int so_ngay_lam);

        void Nhap() override;
        void Xuat() const override;
        ll TienLuong() const override;
};

NhanVienVanPhong::NhanVienVanPhong(string ho_ten, Date ngay_sinh, int so_ngay_lam)
    : NhanVien(ho_ten, ngay_sinh), so_ngay_lam(so_ngay_lam) {}

int NhanVienVanPhong::GetSoNgayLam() const { return so_ngay_lam; }

void NhanVienVanPhong::SetSoNgayLam(int so_ngay_lam) { this->so_ngay_lam = so_ngay_lam; }

void NhanVienVanPhong::Nhap()
{
    NhanVien::Nhap();
    cout << "Nhap so ngay lam: ";cin >> so_ngay_lam;
}

void NhanVienVanPhong::Xuat() const
{
    NhanVien::Xuat();
    cout << "So ngay lam: " << so_ngay_lam << endl;
}

ll NhanVienVanPhong::TienLuong() const
{
    return so_ngay_lam * 100000;
}
