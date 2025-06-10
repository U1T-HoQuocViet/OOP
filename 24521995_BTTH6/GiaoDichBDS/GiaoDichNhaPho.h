#pragma once
#include "GiaoDichBatDongSan.h"

class GiaoDichNhaPho : public GiaoDichBDS
{
    private:
        string ma_can;
        string dia_chi;
    public:
        GiaoDichNhaPho(string = "", Date = Date(), ll = 0, int = 0, string = "", string = "");

        string GetLoaiNha() const;
        string GetDiaChi() const;

        void SetLoaiNha(string);
        void SetDiaChi(string);

        void Nhap();
        void Xuat() const;
        ll ThanhTien() const;
        string GetLoaiGiaoDich() const { return "Nha Pho"; }

};

GiaoDichNhaPho::GiaoDichNhaPho(string ma_giao_dich, Date ngay_giao_dich, ll don_gia, int so_luong, string loai_nha, string dia_chi) 
    : GiaoDichBDS(ma_giao_dich, ngay_giao_dich, don_gia, so_luong), ma_can(loai_nha), dia_chi(dia_chi) {}

string GiaoDichNhaPho::GetLoaiNha() const { return ma_can; }
string GiaoDichNhaPho::GetDiaChi() const { return dia_chi; }

void GiaoDichNhaPho::SetLoaiNha(string loai_nha) { this->ma_can = loai_nha; }
void GiaoDichNhaPho::SetDiaChi(string dia_chi) { this->dia_chi = dia_chi; }

void GiaoDichNhaPho::Nhap()
{
    GiaoDichBDS::Nhap();
    cin.ignore();
    cout << "Nhap loai nha: ";
    getline(cin, ma_can);
    cout << "Nhap dia chi: ";
    getline(cin, dia_chi);
}

void GiaoDichNhaPho::Xuat() const
{
    GiaoDichBDS::Xuat();
    cout << "Loai nha: " << ma_can << endl;
    cout << "Dia chi: " << dia_chi << endl;
}

ll GiaoDichNhaPho::ThanhTien() const
{
    if(ma_can == "cao cap")
        return don_gia * dien_tich;
    return don_gia * dien_tich * 0.9;
}
