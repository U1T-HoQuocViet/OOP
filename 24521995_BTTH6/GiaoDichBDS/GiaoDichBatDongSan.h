#pragma once

#include <iostream>
#include <string>
#include "..\Date.h"

using namespace std;

#define ll long long

class GiaoDichBDS
{
    protected:
        string ma_giao_dich;
        Date ngay_giao_dich;
        ll don_gia;
        int dien_tich;
    public:
        GiaoDichBDS(string = "", Date = Date(), ll = 0, int = 0);

        string GetMaGiaoDich() const;
        Date GetNgayGiaoDich() const;
        ll GetDonGia() const;
        int GetDienTich() const;

        void SetNgayGiaoDich(Date);
        void SetDonGia(ll);
        void SetDienTich(int);

        virtual void Nhap();
        virtual void Xuat() const;
        virtual ll ThanhTien() const = 0;
        virtual string GetLoaiGiaoDich() const = 0;
};

GiaoDichBDS::GiaoDichBDS(string ma_giao_dich, Date ngay_giao_dich, ll don_gia, int dien_tich) 
    : ma_giao_dich(ma_giao_dich), ngay_giao_dich(ngay_giao_dich), don_gia(don_gia), dien_tich(dien_tich) {}


string GiaoDichBDS::GetMaGiaoDich() const { return ma_giao_dich; }
Date GiaoDichBDS::GetNgayGiaoDich() const { return ngay_giao_dich; }
ll GiaoDichBDS::GetDonGia() const { return don_gia; }
int GiaoDichBDS::GetDienTich() const { return dien_tich; }

void GiaoDichBDS::SetNgayGiaoDich(Date ngay_giao_dich) { this->ngay_giao_dich = ngay_giao_dich; }
void GiaoDichBDS::SetDonGia(ll don_gia) { this->don_gia = don_gia; }
void GiaoDichBDS::SetDienTich(int dien_tich) { this->dien_tich = dien_tich; }

void GiaoDichBDS::Nhap()
{
    cout << "Nhap ma giao dich: ";
    getline(cin, ma_giao_dich);
    cout << "Nhap ngay giao dich: ";
    cin >> ngay_giao_dich;
    cout << "Nhap don gia: ";
    cin >> don_gia;
    cout << "Nhap dien tich: ";
    cin >> dien_tich;
}

void GiaoDichBDS::Xuat() const
{
    cout << "-------" << endl;
    cout << "Ma giao dich: " << ma_giao_dich << endl;
    cout << "Ngay giao dich: " << ngay_giao_dich << endl;
    cout << "Don gia: " << don_gia << endl;
    cout << "Dien tich: " << dien_tich << endl;
}
