#pragma once

#include <iostream>
#include <string>

using namespace std;
#define ll long long
class NhanVien 
{
    protected:
        string ma_nv;
        string ten_nv;
        int tuoi_nv;
        string sdt;
        string email;
        ll luong_co_ban;

    public:
        NhanVien(string = "", string = "", int = 0, string = "", string = "", ll = 0);

        string GetMaNV() const;
        string GetTenNV() const;
        int GetTuoiNV() const;
        string GetSDT() const;
        string GetEmail() const;
        ll GetLuongCoBan() const;

        void SetTenNV(string);
        void SetTuoiNV(int);
        void SetSDT(string);
        void SetEmail(string);
        void SetLuongCoBan(ll);

        virtual void Nhap();
        virtual void Xuat() const;
        virtual string GetLoaiNV() const = 0;
        virtual ll TinhLuong() const = 0;
};

NhanVien::NhanVien(string ma_nv, string ten_nv, int tuoi_nv, string sdt, string email, ll luong_co_ban)
    : ma_nv(ma_nv), ten_nv(ten_nv), tuoi_nv(tuoi_nv), sdt(sdt), email(email), luong_co_ban(luong_co_ban) {}

string NhanVien::GetMaNV() const { return ma_nv; }
string NhanVien::GetTenNV() const { return ten_nv; }
int NhanVien::GetTuoiNV() const { return tuoi_nv; }
string NhanVien::GetSDT() const { return sdt; }
string NhanVien::GetEmail() const { return email; }
ll NhanVien::GetLuongCoBan() const { return luong_co_ban; }

void NhanVien::SetTenNV(string ten_nv) { this->ten_nv = ten_nv; }
void NhanVien::SetTuoiNV(int tuoi_nv) { this->tuoi_nv = tuoi_nv; }
void NhanVien::SetSDT(string sdt) { this->sdt = sdt; }
void NhanVien::SetEmail(string email) { this->email = email; }
void NhanVien::SetLuongCoBan(ll luong_co_ban) { this->luong_co_ban = luong_co_ban; }

void NhanVien::Nhap() 
{
    cout << "Nhap ma nhan vien: ";
    getline(cin, ma_nv);
    cout << "Nhap ten nhan vien: ";
    getline(cin, ten_nv);
    cout << "Nhap tuoi nhan vien: ";
    cin >> tuoi_nv;
    cin.ignore();
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
    cout << "Nhap email: ";
    getline(cin, email);
    cout << "Nhap luong co ban: ";
    cin >> luong_co_ban;
}

void NhanVien::Xuat() const 
{
    cout << "----------------------------" << endl;
    cout << "+ Ma nhan vien: " << ma_nv << endl;
    cout << "+ Ten nhan vien: " << ten_nv << endl;
    cout << "+ Tuoi nhan vien: " << tuoi_nv << endl;
    cout << "+ So dien thoai: " << sdt << endl;
    cout << "+ Email: " << email << endl;
    cout << "+ Luong co ban: " << luong_co_ban << endl;
}




