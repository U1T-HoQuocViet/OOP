#pragma once

#include <iostream>
#include <fstream>


using namespace std;

class KhachHang
{
    protected:
        string ten_khach_hang;
        int so_luong_hang;
        int don_gia_hang;

    public:
        KhachHang(string = "", int = 0, int = 0);

        string GetTenKhachHang() const;
        int GetSoLuongHang() const;
        int GetDonGiaHang() const;

        void SetTenKhachHang(string);
        void SetSoLuongHang(int);
        void SetDonGiaHang(int);

        virtual void Nhap(ifstream&);
        virtual void Xuat(ofstream&) const;
        virtual int TinhTien() const = 0;
        virtual string GetLoaiKhachHang() const = 0;

};

KhachHang::KhachHang(string ten_khach_hang, int so_luong_hang, int don_gia_hang)
    : ten_khach_hang(ten_khach_hang), so_luong_hang(so_luong_hang), don_gia_hang(don_gia_hang) {}

string KhachHang::GetTenKhachHang() const { return ten_khach_hang; }
int KhachHang::GetSoLuongHang() const { return so_luong_hang; }
int KhachHang::GetDonGiaHang() const { return don_gia_hang; }

void KhachHang::SetTenKhachHang(string ten_khach_hang) { this->ten_khach_hang = ten_khach_hang; }
void KhachHang::SetSoLuongHang(int so_luong_hang) { this->so_luong_hang = so_luong_hang; }
void KhachHang::SetDonGiaHang(int don_gia_hang) { this->don_gia_hang = don_gia_hang; }

void KhachHang::Nhap(ifstream& file)
{
    getline(file, ten_khach_hang);
    file >> so_luong_hang >> don_gia_hang;
    file.ignore();
}

void KhachHang::Xuat(ofstream& file) const
{
    file << ten_khach_hang << endl;
    file << TinhTien() << endl;
}
