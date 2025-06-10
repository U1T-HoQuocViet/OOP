#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"
#include <vector>
#include <algorithm>

class CongTy 
{
    private:
        vector<NhanVien*> ds_nv;
        int so_nv;

    public:
        ~CongTy();

        void NhapDSNhanVien();
        void XuatDSNhanVien() const;

        ll TongTienLuongPhaiTra() const;


        NhanVienSanXuat* TienLuongThapNhat() const;
        NhanVienVanPhong* TuoiCaoNhat() const;
};

CongTy::~CongTy() 
{
    if(ds_nv.empty()) return;
    for (NhanVien* nv : ds_nv) 
        delete nv;
    so_nv = 0;
    ds_nv.clear();
}   

void CongTy::NhapDSNhanVien() 
{    
    if(!ds_nv.empty()) 
        this->~CongTy();
    
    cout << "Nhap so luong nhan vien: ";
     cin >> so_nv; cin.ignore();
    for (int i = 0; i < so_nv; i++) 
    {
        int loai_nv;
        cout << "Nhap loai nhan vien (1: San Xuat, 2: Van Phong): ";
        cin >> loai_nv; cin.ignore();
        NhanVien* nv = nullptr;
        if (loai_nv == 1) 
        {
            nv = new NhanVienSanXuat();
        } 
        else if (loai_nv == 2) 
        {
            nv = new NhanVienVanPhong();
        }
        else 
        {
            cout << "Loai nhan vien khong hop le! Vui long nhap lai.\n";
            i--;
            continue;
        }
        nv->Nhap();cin.ignore();
        ds_nv.push_back(nv);
    }
}

void CongTy::XuatDSNhanVien() const 
{
    if (ds_nv.empty()) 
    {
        cout << "Danh sach nhan vien rong.\n";
        return;
    }
    cout << "Danh sach nhan vien:\n";
    for (const NhanVien* nv : ds_nv) 
    {
        cout << *nv;
        cout << " -> Tien luong: " << nv->TienLuong() << endl;
    }
}

ll CongTy::TongTienLuongPhaiTra() const 
{
    ll tong_tien = 0;
    for (const NhanVien* nv : ds_nv) 
    {
        tong_tien += nv->TienLuong();
    }
    return tong_tien;
}

NhanVienSanXuat* CongTy::TienLuongThapNhat() const 
{
    NhanVienSanXuat* min_nv = nullptr;
    for (NhanVien* nv : ds_nv) 
    {
        NhanVienSanXuat* nvsx = dynamic_cast<NhanVienSanXuat*>(nv);
        if (nvsx != nullptr) 
        {
            if (min_nv == nullptr || nvsx->TienLuong() < min_nv->TienLuong()) 
                min_nv = nvsx;
        }
    }
    return min_nv;
}

NhanVienVanPhong* CongTy::TuoiCaoNhat() const 
{
    NhanVienVanPhong* max_nv = nullptr;
    for (NhanVien* nv : ds_nv) 
    {
        NhanVienVanPhong* nvvp = dynamic_cast<NhanVienVanPhong*>(nv);
        if (nvvp != nullptr) 
        {
            if (max_nv == nullptr || Date::QuyDoi(nvvp->GetNgaySinh()) < Date::QuyDoi(max_nv->GetNgaySinh())) 
                max_nv = nvvp;
        }
    }
    return max_nv;
}

