#pragma once
#include "GiaoDichBatDongSan.h"


class GiaoDichDat : public GiaoDichBDS
{
    private:
        string loai_dat;
    public:
        GiaoDichDat(string = "", Date = Date(), ll = 0, int = 0, string = "");

        string GetLoaiDat() const;

        void SetLoaiDat(string);

        void Nhap();
        void Xuat() const;
        ll ThanhTien() const;
        string GetLoaiGiaoDich() const { return "Dat"; }

};

GiaoDichDat::GiaoDichDat(string ma_giao_dich, Date ngay_giao_dich, ll don_gia, int so_luong, string loai_dat) 
    : GiaoDichBDS(ma_giao_dich, ngay_giao_dich, don_gia, so_luong), loai_dat(loai_dat) {}

string GiaoDichDat::GetLoaiDat() const { return loai_dat; }

void GiaoDichDat::SetLoaiDat(string loai_dat) { this->loai_dat = loai_dat; }

void GiaoDichDat::Nhap()
{
    GiaoDichBDS::Nhap();
    cin.ignore();
    cout << "Nhap loai dat: ";
    getline(cin, loai_dat);
}

void GiaoDichDat::Xuat() const
{
    GiaoDichBDS::Xuat();
    cout << "Loai dat: " << loai_dat << endl;
}

ll GiaoDichDat::ThanhTien() const
{
    if(loai_dat == "A")
        return don_gia * dien_tich * 1.5;
    return don_gia * dien_tich;
}
