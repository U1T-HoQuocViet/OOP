#pragma once

#include <iostream>
#include <string>
#include "../Date.h"

using namespace std;

#define ll long long

class NhanVien
{
    protected:
        string ho_ten;
        Date ngay_sinh;
    public:
        NhanVien(string = "", Date = Date());

        string GetHoTen() const;
        Date GetNgaySinh() const;

        void SetHoTen(string);
        void SetNgaySinh(Date);

        virtual void Nhap();
        virtual void Xuat() const;
        virtual ll TienLuong() const = 0;

        friend istream& operator>>(istream &is, NhanVien &nv);
        friend ostream& operator<<(ostream &os, const NhanVien &nv);
};



NhanVien::NhanVien(string ho_ten, Date ngay_sinh)
    : ho_ten(ho_ten), ngay_sinh(ngay_sinh) {}


string NhanVien::GetHoTen() const { return ho_ten; }
Date NhanVien::GetNgaySinh() const { return ngay_sinh; }

void NhanVien::SetHoTen(string ho_ten) { this->ho_ten = ho_ten; }
void NhanVien::SetNgaySinh(Date ngay_sinh) { this->ngay_sinh = ngay_sinh; }

void NhanVien::Nhap()
{
    cout << "Nhap ho ten: ";
    getline(cin, ho_ten);
    cout << "Nhap ngay sinh (dd mm yyyy): ";
    cin >> ngay_sinh;
}

void NhanVien::Xuat() const
{
    cout << "Ho ten: " << ho_ten << endl;
    cout << "Ngay sinh: " << ngay_sinh << endl;
}

istream& operator>>(istream &is, NhanVien &nv)
{
    nv.Nhap();
    return is;
}

ostream& operator<<(ostream &os, const NhanVien &nv)
{
    nv.Xuat();
    return os;
}