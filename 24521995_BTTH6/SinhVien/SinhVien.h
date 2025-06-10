#pragma once

#include <iostream>
#include <string>
#include "../Date.h"

using namespace std;


class SinhVien
{
    protected:
        string ma_sinh_vien;
        string ho_ten;
        string dia_chi;
        int tong_so_tin_chi;
        float diem_trung_binh;

    public:
        SinhVien(string = "", string = "", string = "", int = 0, float = 0.0);

        string GetMaSinhVien() const;
        string GetHoTen() const;
        string GetDiaChi() const;
        int GetTongSoTinChi() const;
        float GetDiemTrungBinh() const;

        void SetHoTen(string);
        void SetDiaChi(string);
        void SetTongSoTinChi(int);
        void SetDiemTrungBinh(float);

        virtual void Nhap();
        virtual void Xuat() const;
        virtual bool XetTotNghiep() const = 0;
        virtual string GetLoaiSinhVien() const = 0;

        friend istream& operator>>(istream &is, SinhVien &sv);
        friend ostream& operator<<(ostream &os, const SinhVien &sv);



};


SinhVien::SinhVien(string ma_sinh_vien, string ho_ten, string dia_chi, int tong_so_tin_chi, float diem_trung_binh)
    : ma_sinh_vien(ma_sinh_vien), ho_ten(ho_ten), dia_chi(dia_chi), tong_so_tin_chi(tong_so_tin_chi), diem_trung_binh(diem_trung_binh) {}

string SinhVien::GetMaSinhVien() const { return ma_sinh_vien; }
string SinhVien::GetHoTen() const { return ho_ten; }
string SinhVien::GetDiaChi() const { return dia_chi; }
int SinhVien::GetTongSoTinChi() const { return tong_so_tin_chi; }
float SinhVien::GetDiemTrungBinh() const { return diem_trung_binh; }

void SinhVien::SetHoTen(string ho_ten) { this->ho_ten = ho_ten; }
void SinhVien::SetDiaChi(string dia_chi) { this->dia_chi = dia_chi; }
void SinhVien::SetTongSoTinChi(int tong_so_tin_chi) { this->tong_so_tin_chi = tong_so_tin_chi; }
void SinhVien::SetDiemTrungBinh(float diem_trung_binh) { this->diem_trung_binh = diem_trung_binh; }

void SinhVien::Nhap()
{
    cout << "Nhap ma sinh vien: ";
    getline(cin, ma_sinh_vien);
    cout << "Nhap ho ten: ";
    getline(cin, ho_ten);
    cout << "Nhap dia chi: ";
    getline(cin, dia_chi);
    cout << "Nhap tong so tin chi: ";
    cin >> tong_so_tin_chi;
    cout << "Nhap diem trung binh: ";
    cin >> diem_trung_binh;
}

void SinhVien::Xuat() const
{
    cout << "----------\n";
    cout << "Ma sinh vien: " << ma_sinh_vien << endl;
    cout << "Ho ten: " << ho_ten << endl;
    cout << "Dia chi: " << dia_chi << endl;
    cout << "Tong so tin chi: " << tong_so_tin_chi << endl;
    cout << "Diem trung binh: " << diem_trung_binh << endl;
}

istream& operator>>(istream &is, SinhVien &sv)
{
    sv.Nhap();
    return is;
}

ostream& operator<<(ostream &os, const SinhVien &sv)
{
    sv.Xuat();
    return os;
}