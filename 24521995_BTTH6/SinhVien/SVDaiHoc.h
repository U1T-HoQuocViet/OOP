#pragma#pragma once

#include "SinhVien.h"

class SVDaiHoc : public SinhVien
{
    private:
        string ten_luan_van;
        float diem_luan_van;
    public:
        SVDaiHoc(string = "", string = "", string = "", int = 0, float = 0.0, string = "", float = 0.0);

        float GetDiemThiTN() const;

        void SetDiemThiTN(float);

        void Nhap();
        void Xuat() const;
        bool XetTotNghiep() const;
        string GetLoaiSinhVien() const { return "Dai Hoc"; }
};

SVDaiHoc::SVDaiHoc(string ma_sinh_vien, string ho_ten, string dia_chi, int tong_so_tin_chi, float diem_trung_binh, string ten_luan_van, float diem_luan_van)
    : SinhVien(ma_sinh_vien, ho_ten, dia_chi, tong_so_tin_chi, diem_trung_binh), ten_luan_van(ten_luan_van), diem_luan_van(diem_luan_van) {}


void SVDaiHoc::Nhap()
{
    SinhVien::Nhap();
    cin.ignore();
    cout << "Nhap ten luan van: ";
    getline(cin, ten_luan_van);
    cout << "Nhap diem luan van: ";cin >> diem_luan_van;
}

void SVDaiHoc::Xuat() const
{
    SinhVien::Xuat();
    cout << "Ten luan van: " << ten_luan_van << endl;
    cout << "Diem luan van: " << diem_luan_van << endl;
}

bool SVDaiHoc::XetTotNghiep() const
{
    return tong_so_tin_chi >= 170 && diem_trung_binh >= 5.0 && diem_luan_van >= 5.0;
}

