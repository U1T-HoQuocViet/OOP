#pragma once

#include "Giaodich.h"

using namespace std;

// enum LoaiNgoaiTe
// {
//     VND,
//     USD,
//     EUR
// };

class GiaoDichNgoaiTe : public GiaoDich
{
    private:
        float ti_gia;
        string loai_tien; // "USD", "EUR", "VND"

    public:
        GiaoDichNgoaiTe(string = "", Date = Date(), int = 0, int = 0, float = 0, string = "");
        GiaoDichNgoaiTe(const GiaoDichNgoaiTe &gdv);
        GiaoDichNgoaiTe(const GiaoDich &gd, string loai_tien);
        ~GiaoDichNgoaiTe();

        float GetTiGia() const;
        string GetLoaiTien() const;

        void SetTiGia(float);
        void SetLoaiTien(string);

        void Nhap() override;
        void Xuat() const override;
        ll ThanhTien() const override;

        friend istream& operator>>(istream &is, GiaoDichNgoaiTe &gdv);
        friend ostream& operator<<(ostream &os, const GiaoDichNgoaiTe &gdv);
};


GiaoDichNgoaiTe::GiaoDichNgoaiTe(string ma_giao_dich, Date ngay_giao_dich, int don_gia, int so_luong, float ti_gia, string loai_tien) 
    : GiaoDich(ma_giao_dich, ngay_giao_dich, don_gia, so_luong), ti_gia(ti_gia), loai_tien(loai_tien) {}

GiaoDichNgoaiTe::GiaoDichNgoaiTe(const GiaoDichNgoaiTe &gdv)
    : GiaoDich(gdv), ti_gia(gdv.ti_gia), loai_tien(gdv.loai_tien) {}

GiaoDichNgoaiTe::GiaoDichNgoaiTe(const GiaoDich &gd, string loai_tien)
    : GiaoDich(gd), ti_gia(0), loai_tien(loai_tien) {}

GiaoDichNgoaiTe::~GiaoDichNgoaiTe() {}

float GiaoDichNgoaiTe::GetTiGia() const { return ti_gia; }
string GiaoDichNgoaiTe::GetLoaiTien() const { return loai_tien; }

void GiaoDichNgoaiTe::SetTiGia(float ti_gia) { this->ti_gia = ti_gia; }
void GiaoDichNgoaiTe::SetLoaiTien(string loai_tien) { this->loai_tien = loai_tien; }

void GiaoDichNgoaiTe::Nhap()
{
    GiaoDich::Nhap();
    cout << "Nhap ti gia: ";
    cin >> ti_gia;
    cin.ignore();
    cout << "Nhap loai tien: ";
    getline(cin, loai_tien);
}

void GiaoDichNgoaiTe::Xuat() const
{
    GiaoDich::Xuat();
    cout << "Ti gia: " << ti_gia << endl;
    cout << "Loai tien: " << loai_tien << endl;
}

ll GiaoDichNgoaiTe::ThanhTien() const
{
    return don_gia * so_luong * ti_gia;
}

istream& operator>>(istream &is, GiaoDichNgoaiTe &gdnt)
{
    gdnt.Nhap();
    return is;
}

ostream& operator<<(ostream &os, const GiaoDichNgoaiTe &gdnt)
{
    gdnt.Xuat();
    return os;
}