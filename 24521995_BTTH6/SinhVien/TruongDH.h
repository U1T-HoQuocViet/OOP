#include "SVDaiHoc.h"
#include "SVCaoDang.h"
#include <vector>
#include <algorithm>

class TruongDH 
{
    private:
        vector<SinhVien*> ds_sv;
        int so_sv;

    public:
        ~TruongDH();

        void NhapDSSinhVien();
        void XuatDSSinhVien() const;

        void XuatSVTotNghiep() const;
        void XuatSVKhongDuDieuKienTotNghiep() const;


        SVDaiHoc* SinhVienDaiHocCoDiemTBCaoNhat() const;
        SVCaoDang* SinhVienCaoDangCoDiemTBCaoNhat() const;
        void SVKhongDuDKTotNghiepTungLoai() const;
};

TruongDH::~TruongDH() 
{
    if(ds_sv.empty()) return;
    for (SinhVien* sv : ds_sv) 
        delete sv;
    so_sv = 0;
    ds_sv.clear();
}

void TruongDH::NhapDSSinhVien() 
{    
    if(!ds_sv.empty()) 
        this->~TruongDH();
    
    cout << "Nhap so luong sinh vien: ";
    cin >> so_sv; cin.ignore();
    for (int i = 0; i < so_sv; i++) 
    {
        int loai_sv;
        cout << "Nhap loai sinh vien (1: Dai Hoc, 2: Cao Dang): ";
        cin >> loai_sv; cin.ignore();
        SinhVien* sv = nullptr;
        if (loai_sv == 1) 
        {
            sv = new SVDaiHoc();
        } 
        else if (loai_sv == 2) 
        {
            sv = new SVCaoDang();
        }
        else 
        {
            cout << "Loai sinh vien khong hop le! Vui long nhap lai.\n";
            i--;
            continue;
        }
        sv->Nhap();cin.ignore();
        ds_sv.push_back(sv);
    }
}

void TruongDH::XuatDSSinhVien() const 
{
    if (ds_sv.empty()) 
    {
        cout << "Danh sach sinh vien rong.\n";
        return;
    }
    cout << "Danh sach sinh vien:\n";
    for (SinhVien* sv : ds_sv) 
    {
        cout << *sv << endl;
    }
}

void TruongDH::XuatSVTotNghiep() const 
{
    cout << "Danh sach sinh vien du dieu kien tot nghiep:\n";
    for (SinhVien* sv : ds_sv) 
    {
        if (sv->XetTotNghiep()) 
            cout << *sv;
    }
}

void TruongDH::XuatSVKhongDuDieuKienTotNghiep() const 
{
    cout << "Danh sach sinh vien khong du dieu kien tot nghiep:\n";
    for (SinhVien* sv : ds_sv) 
    {
        if (!sv->XetTotNghiep())
            cout << *sv;
    }
}

SVDaiHoc* TruongDH::SinhVienDaiHocCoDiemTBCaoNhat() const 
{
    SinhVien* max_sv = nullptr;
    for (SinhVien* sv : ds_sv) 
    {
        if (sv->GetLoaiSinhVien() == "Dai Hoc") 
            if (max_sv == nullptr || sv->GetDiemTrungBinh() > max_sv->GetDiemTrungBinh()) 
                max_sv = sv;
        
    }
    return dynamic_cast<SVDaiHoc*>(max_sv);
}

SVCaoDang* TruongDH::SinhVienCaoDangCoDiemTBCaoNhat() const 
{
    SVCaoDang* max_sv = nullptr;
    for (const SinhVien* sv : ds_sv) 
    {
        const SVCaoDang* svcd = dynamic_cast<const SVCaoDang*>(sv);
        if (svcd != nullptr) 
        {
            if (max_sv == nullptr || svcd->GetDiemTrungBinh() > max_sv->GetDiemTrungBinh()) 
            {
                max_sv = const_cast<SVCaoDang*>(svcd);
            }
        }
    }
    return max_sv;
}

void TruongDH::SVKhongDuDKTotNghiepTungLoai() const 
{
    int c_1 = 0, c_2 = 0;
    for (const SinhVien* sv : ds_sv) 
    {
        if (!sv->XetTotNghiep()) 
        {
            if (const SVDaiHoc* svdh = dynamic_cast<const SVDaiHoc*>(sv)) 
                c_1++;
            else
                c_2++;
            
        }
    }
    cout<< " - So luong sinh vien dai hoc khong du dieu kien tot nghiep: " << c_1 << endl;
    cout<< " - So luong sinh vien cao dang khong du dieu kien tot nghiep: " << c_2 << endl;
}

