#pragma once

#include "SinhVien.h"

class SVCaoDang : public SinhVien
{
    private:
        float diem_thi_tn;
    public:
        SVCaoDang(string = "", string = "", string = "", int = 0, float = 0.0, float = 0.0);

        float GetDiemThiTN() const;

        void SetDiemThiTN(float);

        void Nhap();
        void Xuat() const;
        bool XetTotNghiep() const;
        string GetLoaiSinhVien() const { return "Cao Dang"; }
};

SVCaoDang::SVCaoDang(string ma_sinh_vien, string ho_ten, string dia_chi, int tong_so_tin_chi, float diem_trung_binh, float diem_thi_tn)
    : SinhVien(ma_sinh_vien, ho_ten, dia_chi, tong_so_tin_chi, diem_trung_binh), diem_thi_tn(diem_thi_tn) {}

float SVCaoDang::GetDiemThiTN() const { return diem_thi_tn; }

void SVCaoDang::SetDiemThiTN(float diem_thi_tn) { this->diem_thi_tn = diem_thi_tn; }

void SVCaoDang::Nhap()
{
    SinhVien::Nhap();
    cout << "Nhap diem thi tot nghiep: ";
    cin >> diem_thi_tn;
}

void SVCaoDang::Xuat() const
{
    SinhVien::Xuat();
    cout << "Diem thi tot nghiep: " << diem_thi_tn << endl;
}

bool SVCaoDang::XetTotNghiep() const
{
    return tong_so_tin_chi >= 120 && diem_trung_binh >= 5.0 && diem_thi_tn >= 5.0;
}

