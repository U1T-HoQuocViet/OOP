#pragma once

#include "Giaodich.h"

using namespace std;


class GiaoDichVang : public GiaoDich
{
    private:
        string loai_vang;
    public:
        GiaoDichVang(string = "", Date = Date(), int = 0, int = 0, string = "");
        GiaoDichVang(const GiaoDichVang &gdv);
        GiaoDichVang(const GiaoDich &gd, string loai_vang);
        ~GiaoDichVang();

        string GetLoaiVang() const;

        void SetLoaiVang(string);
        
        void Nhap() override;
        void Xuat() const override;
        ll ThanhTien() const override;

        friend istream& operator>>(istream &is, GiaoDichVang &gdv);
        friend ostream& operator<<(ostream &os, const GiaoDichVang &gdv);
};


GiaoDichVang::GiaoDichVang(string ma_giao_dich, Date ngay_giao_dich, int don_gia, int so_luong, string loai_vang) 
    : GiaoDich(ma_giao_dich, ngay_giao_dich, don_gia, so_luong), loai_vang(loai_vang) {}

GiaoDichVang::GiaoDichVang(const GiaoDichVang &gdv)
    : GiaoDich(gdv), loai_vang(gdv.loai_vang) {}

GiaoDichVang::GiaoDichVang(const GiaoDich &gd, string loai_vang)
    : GiaoDich(gd), loai_vang(loai_vang) {}

GiaoDichVang::~GiaoDichVang() {}

string GiaoDichVang::GetLoaiVang() const { return loai_vang; }

void GiaoDichVang::SetLoaiVang(string loai_vang) { this->loai_vang = loai_vang; }

void GiaoDichVang::Nhap()
{
    GiaoDich::Nhap();
    cin.ignore();
    cout << "Nhap loai vang: ";
    getline(cin, loai_vang);
}

void GiaoDichVang::Xuat() const
{
    GiaoDich::Xuat();
    cout << "Loai vang: " << loai_vang << endl;
}

ll GiaoDichVang::ThanhTien() const
{
    return don_gia * so_luong;
}

istream& operator>>(istream &is, GiaoDichVang &gdv)
{
    gdv.Nhap();
    return is;
}

ostream& operator<<(ostream &os, const GiaoDichVang &gdv)
{
    gdv.Xuat();
    return os;
}