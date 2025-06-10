#include <vector>
#include "GiaoDichNhaPho.h"
#include "GiaoDichDat.h"
#include "GiaoDichCanHo.h" 


class QuanLyBDS
{
    private:
        vector<GiaoDichBDS*> ds_gd_bds;
        int so_gd_bds;
        bool KiemTraGiaoDich(GiaoDichBDS* gd) const;

    public:
        ~QuanLyBDS();

        void NhapDSGiaoDichBDS();

        void SoLuongTungGiaoDich() const;
        ll TrungBinhThanhTienChungCu() const;
        GiaoDichNhaPho* TimGiaoDichNhaPhoCaoNhat() const;
        void XuatCacGiaoDichVaoNgayCuThe() const;
};

QuanLyBDS::~QuanLyBDS() 
{
    for (GiaoDichBDS* gd : ds_gd_bds) 
        delete gd;
    ds_gd_bds.clear();
    so_gd_bds = 0;
}

void QuanLyBDS::NhapDSGiaoDichBDS() 
{
    cout << "Nhap so luong giao dich bat dong san: ";
    cin >> so_gd_bds;
    cin.ignore();

    for (int i = 0; i < so_gd_bds; ++i) 
    {
        int loai_gd;
        cout << "Nhap loai giao dich (1: Dat, 2: Can Ho, 3: Nha Pho): ";
        cin >> loai_gd;
        cin.ignore();

        GiaoDichBDS* gd = nullptr;
        if (loai_gd == 1) 
            gd = new GiaoDichDat();
        else if (loai_gd == 2) 
            gd = new GiaoDichCanHo();
        else if (loai_gd == 3) 
            gd = new GiaoDichNhaPho();
        else 
        {
            cout << "Loai giao dich khong hop le! Vui long nhap lai.\n";
            --i;
            continue;
        }

        gd->Nhap();
        ds_gd_bds.push_back(gd);
    }
}

void QuanLyBDS::SoLuongTungGiaoDich() const 
{
    int so_dat = 0, so_can_ho = 0, so_nha_pho = 0;

    for (const GiaoDichBDS* gd : ds_gd_bds) 
    {
        if (gd->GetLoaiGiaoDich() == "Dat")
            ++so_dat;
        else if (gd->GetLoaiGiaoDich() == "Can Ho")
            ++so_can_ho;
        else if (gd->GetLoaiGiaoDich() == "Nha Pho")
            ++so_nha_pho;
    }
    cout << "So luong giao dich Dat: " << so_dat << endl;
    cout << "So luong giao dich Can Ho: " << so_can_ho << endl;
    cout << "So luong giao dich Nha Pho: " << so_nha_pho << endl;
}

ll QuanLyBDS::TrungBinhThanhTienChungCu() const 
{
    ll tong_thanh_tien = 0;
    int so_luong_chung_cu = 0;

    for (const GiaoDichBDS* gd : ds_gd_bds) 
    {
        if (gd->GetLoaiGiaoDich() == "Can Ho") 
        {
            tong_thanh_tien += gd->ThanhTien();
            ++so_luong_chung_cu;
        }
    }

    return so_luong_chung_cu > 0 ? tong_thanh_tien / so_luong_chung_cu : 0;
}

GiaoDichNhaPho* QuanLyBDS::TimGiaoDichNhaPhoCaoNhat() const 
{
    GiaoDichBDS* gd_cao_nhat = nullptr;

    for (GiaoDichBDS* gd : ds_gd_bds) 
    {
        if (gd->GetLoaiGiaoDich() == "Nha Pho") 
        {
            
            if (gd_cao_nhat == nullptr || gd->ThanhTien() > gd_cao_nhat->ThanhTien()) 
            {
                gd_cao_nhat = gd;
            }
        }
    }

    return dynamic_cast<GiaoDichNhaPho*>(gd_cao_nhat);
}

bool QuanLyBDS::KiemTraGiaoDich(GiaoDichBDS* gd) const 
{
    return gd->GetNgayGiaoDich().GetMonth() == 12 && gd->GetNgayGiaoDich().GetYear() == 2024; 
}

void QuanLyBDS::XuatCacGiaoDichVaoNgayCuThe() const 
{
    cout << "Cac giao dich vao 12/2024:\n";
    for (GiaoDichBDS* gd : ds_gd_bds) 
    {
        if (KiemTraGiaoDich(gd))
            gd->Xuat();
    }
}
