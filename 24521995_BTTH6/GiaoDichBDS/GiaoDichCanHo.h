#pragma once
#include "GiaoDichBatDongSan.h"

class GiaoDichCanHo : public GiaoDichBDS
{
    private:
        int vi_tri_tang;
        string ma_can;
    public:
        GiaoDichCanHo(string = "", Date = Date(), ll = 0, int = 0, int = 0, string = "");

        int GetViTriTang() const;
        string GetMaCan() const;

        void SetViTriTang(int);
        void SetMaCan(string);

        void Nhap();
        void Xuat() const;
        ll ThanhTien() const;
        string GetLoaiGiaoDich() const { return "Can Ho"; }

};

GiaoDichCanHo::GiaoDichCanHo(string ma_giao_dich, Date ngay_giao_dich, ll don_gia, int dien_tich, int vi_tri_tang, string ma_can) 
    : GiaoDichBDS(ma_giao_dich, ngay_giao_dich, don_gia, dien_tich), vi_tri_tang(vi_tri_tang), ma_can(ma_can) {}

int GiaoDichCanHo::GetViTriTang() const { return vi_tri_tang; }
string GiaoDichCanHo::GetMaCan() const { return ma_can; }

void GiaoDichCanHo::SetViTriTang(int vi_tri_tang) { this->vi_tri_tang = vi_tri_tang; }
void GiaoDichCanHo::SetMaCan(string ma_can) { this->ma_can = ma_can; }

void GiaoDichCanHo::Nhap()
{
    GiaoDichBDS::Nhap();
    cout << "Nhap vi tri tang: ";
    cin >> vi_tri_tang;
    cin.ignore();
    cout << "Nhap ma can: ";
    getline(cin, ma_can);
}

void GiaoDichCanHo::Xuat() const
{
    GiaoDichBDS::Xuat();
    cout << "Vi tri tang: " << vi_tri_tang << endl;
    cout << "Ma can: " << ma_can << endl;
}

ll GiaoDichCanHo::ThanhTien() const
{
    if(vi_tri_tang == 1)
        return don_gia * dien_tich * 2;
    else if(vi_tri_tang > 15)
        return don_gia * dien_tich * 1.2;
    else
        return don_gia * dien_tich;
}
