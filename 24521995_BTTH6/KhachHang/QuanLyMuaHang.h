#include "KHBinhThuong.h"
#include "KHDacBiet.h"
#include "KHThanThiet.h"
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class QuanLyMuaHang
{
    private:
        vector<KhachHang*> ds_khach_hang;
        int x, y, z;//BT, TT, DB;

    public:
        ~QuanLyMuaHang();


        void TaiTepKhachHang(string);
        void GhiTepKhachHang(string) const;

        long long TinhTongTien() const;
};

QuanLyMuaHang::~QuanLyMuaHang()
{
    for (KhachHang* kh : ds_khach_hang) 
        delete kh;
    
    ds_khach_hang.clear();
    x = y = z = 0;
}

void QuanLyMuaHang::TaiTepKhachHang(string dir)
{
    ifstream file(dir);
    if (!file.is_open()) {
        cout << "Khong the mo tep "<< dir << endl;
        return;
    }
    file >> x >> y >> z;
    file.ignore();

    // for(int i = 0; i < x; ++i) 
    // {
    //     KhachHang* kh = new KHBinhThuong();
    //     kh->Nhap(file);
    //     ds_khach_hang.push_back(kh);
    // }

    // for(int i = 0; i < y; ++i) 
    // {
    //     KhachHang* kh = new KHThanThiet();
    //     kh->Nhap(file);
    //     ds_khach_hang.push_back(kh);
    // }

    // for(int i = 0; i < z; ++i) 
    // {
    //     KhachHang* kh = new KHDacBiet();
    //     kh->Nhap(file);
    //     ds_khach_hang.push_back(kh);
    // }

    for(int i = 0; i < x + y + z; ++i) 
    {
        KhachHang* kh = nullptr;
        if(i < x) 
        {
            kh = new KHBinhThuong();
        }
        else if(i < x + y) 
        {
            kh = new KHThanThiet();
        }
        else 
        {
            kh = new KHDacBiet();
        }

        if(kh != nullptr) 
        {
            kh->Nhap(file);
            ds_khach_hang.push_back(kh);
        }
    }
    file.close();
}

void QuanLyMuaHang::GhiTepKhachHang(string dir) const
{
    ofstream file(dir);
    if (!file.is_open()) {
        cout << "Khong the mo tep " << dir << endl;
        return;
    }

    file << x << " " << y << " " << z << endl;

    for (const KhachHang* kh : ds_khach_hang) 
        kh->Xuat(file);

    file << TinhTongTien() << endl;

    file.close();
}

long long QuanLyMuaHang::TinhTongTien() const
{
    long long tong_tien = 0;
    for (const KhachHang* kh : ds_khach_hang) {
        tong_tien += kh->TinhTien();
    }
    return tong_tien;
}