#include "NhanVien/KiemChungVien.h"
#include "NhanVien/LapTrinhVien.h"
#include <vector>

class CongTyPhanMem 
{
    private:
        vector<NhanVien*> ds_nhan_vien;
        int so_nhan_vien;

    public:
        ~CongTyPhanMem();

        void NhapDanhSachNhanVien();
        void XuatDanhSachNhanVien() const;

        ll LuongTrungBinh() const;
        void DanhSachNhanVienCoLuongThapHonTrungBinh() const;

        NhanVien* NhanVienCoLuongCaoNhat() const;
        NhanVien* NhanVienCoLuongThapNhat() const;
        LapTrinhVien* NhanVienLapTrinhCoLuongCaoNhat() const;
        KiemChungVien* NhanVienKiemChungCoLuongThapNhat() const;
};

CongTyPhanMem::~CongTyPhanMem() 
{
    so_nhan_vien = 0;
    for (NhanVien* nv : ds_nhan_vien) 
        delete nv;
}

void CongTyPhanMem::NhapDanhSachNhanVien() 
{
    cout << "Nhap so luong nhan vien: ";
    cin >> so_nhan_vien;
    cin.ignore();

    for (int i = 0; i < so_nhan_vien; ++i) 
    {
        string loai_nv;
        cout << "Nhap loai nhan vien (1 : Kiem Chung Vien, 2 : Lap Trinh Vien): ";
        getline(cin, loai_nv);

        NhanVien* nv = nullptr;
        if (loai_nv == "1")
            nv = new KiemChungVien();
        else if (loai_nv == "2")
            nv = new LapTrinhVien();
        else 
        {
            cout << "Loai nhan vien khong hop le!" << endl;
            i--;
            continue;
        }

        nv->Nhap();
        ds_nhan_vien.push_back(nv);
    }
}


void CongTyPhanMem::XuatDanhSachNhanVien() const 
{
    for (const NhanVien* nv : ds_nhan_vien)
        nv->Xuat();
}

ll CongTyPhanMem::LuongTrungBinh() const 
{
    ll tong_luong = 0;
    for (NhanVien* nv : ds_nhan_vien) 
        tong_luong += nv->TinhLuong();

    return tong_luong / so_nhan_vien;
}

void CongTyPhanMem::DanhSachNhanVienCoLuongThapHonTrungBinh() const 
{
    ll luong_tb = LuongTrungBinh();
    cout << "Danh sach nhan vien co luong thap hon trung binh :" << endl;
    for (NhanVien* nv : ds_nhan_vien)
        if (nv->TinhLuong() < luong_tb)
        {
            nv->Xuat();
            cout << "-> Luong: " << nv->TinhLuong() << endl;
        }
}

NhanVien* CongTyPhanMem::NhanVienCoLuongCaoNhat() const 
{

    NhanVien* max_nv = nullptr;
    for (NhanVien* nv : ds_nhan_vien) 
    {
        if (max_nv == nullptr || nv->TinhLuong() > max_nv->TinhLuong())
            max_nv = nv;
    }
    return max_nv;
}

NhanVien* CongTyPhanMem::NhanVienCoLuongThapNhat() const 
{
    NhanVien* min_nv = nullptr;
    for (NhanVien* nv : ds_nhan_vien) 
        if (nv->TinhLuong() < min_nv->TinhLuong())
            min_nv = nv;
    return min_nv;
}

LapTrinhVien* CongTyPhanMem::NhanVienLapTrinhCoLuongCaoNhat() const 
{
    NhanVien* max_nv = nullptr;
    for (NhanVien* nv : ds_nhan_vien) 
    {
        if (nv->GetLoaiNV() == "Lap Trinh Vien") 
        {
            if (max_nv == nullptr || nv->TinhLuong() > max_nv->TinhLuong())
                max_nv = nv;
        }
    }
    return dynamic_cast<LapTrinhVien*>(max_nv);
}

KiemChungVien* CongTyPhanMem::NhanVienKiemChungCoLuongThapNhat() const 
{
    NhanVien* min_nv = nullptr;
    for (NhanVien* nv : ds_nhan_vien) 
    {
        if (nv->GetLoaiNV() == "Kiem Chung Vien") 
        {
            if (min_nv == nullptr || nv->TinhLuong() < min_nv->TinhLuong())
                min_nv = nv;
        }
    }
    return dynamic_cast<KiemChungVien*>(min_nv);
}