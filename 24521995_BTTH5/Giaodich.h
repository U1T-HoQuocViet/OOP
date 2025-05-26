#pragma once

// #include <iostream>
#include <string>
#include "Date.h"

using namespace std;

#define ll long long

class GiaoDich
{
    protected:
        string ma_giao_dich;
        Date ngay_giao_dich;
        ll don_gia;
        int so_luong;
    public:
        ~GiaoDich();
        GiaoDich(string = "", Date = Date(), ll = 0, int = 0);
        GiaoDich(const GiaoDich &gd);

        string GetMaGiaoDich() const;
        Date GetNgayGiaoDich() const;
        ll GetDonGia() const;
        int GetSoLuong() const;

        void SetMaGiaoDich(string);
        void SetNgayGiaoDich(Date);
        void SetDonGia(ll);
        void SetSoLuong(int);

        virtual void Nhap();
        virtual void Xuat() const;
        virtual ll ThanhTien() const = 0;
};

GiaoDich::~GiaoDich() {}

GiaoDich::GiaoDich(string ma_giao_dich, Date ngay_giao_dich, ll don_gia, int so_luong) 
    : ma_giao_dich(ma_giao_dich), ngay_giao_dich(ngay_giao_dich), don_gia(don_gia), so_luong(so_luong) {}

GiaoDich::GiaoDich(const GiaoDich &gd)
    : ma_giao_dich(gd.ma_giao_dich), ngay_giao_dich(gd.ngay_giao_dich), don_gia(gd.don_gia), so_luong(gd.so_luong) {}

string GiaoDich::GetMaGiaoDich() const { return ma_giao_dich; }
Date GiaoDich::GetNgayGiaoDich() const { return ngay_giao_dich; }
ll GiaoDich::GetDonGia() const { return don_gia; }
int GiaoDich::GetSoLuong() const { return so_luong; }

void GiaoDich::SetMaGiaoDich(string ma_giao_dich) { this->ma_giao_dich = ma_giao_dich; }
void GiaoDich::SetNgayGiaoDich(Date ngay_giao_dich) { this->ngay_giao_dich = ngay_giao_dich; }
void GiaoDich::SetDonGia(ll don_gia) { this->don_gia = don_gia; }
void GiaoDich::SetSoLuong(int so_luong) { this->so_luong = so_luong; }

void GiaoDich::Nhap()
{
    cout << "Nhap ma giao dich: ";
    getline(cin, ma_giao_dich);
    cout << "Nhap ngay giao dich: ";
    cin >> ngay_giao_dich;
    cout << "Nhap don gia: ";
    cin >> don_gia;
    cout << "Nhap so luong: ";
    cin >> so_luong;
}

void GiaoDich::Xuat() const
{
    cout << "-------" << endl;
    cout << "Ma giao dich: " << ma_giao_dich << endl;
    cout << "Ngay giao dich: " << ngay_giao_dich << endl;
    cout << "Don gia: " << don_gia << endl;
    cout << "So luong: " << so_luong << endl;
}
