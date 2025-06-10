#include "NhanVien.h"

class LapTrinhVien : public NhanVien 
{
    private:
        int so_gio_lam_viec;

    public:
        LapTrinhVien(string = "", string = "", int = 0, string = "", string = "", ll = 0, int = 0);

        int GetSoGioLamViec() const;

        void SetSoGioLamViec(int so_gio_lam_viec);

        void Nhap();
        void Xuat() const;
        string GetLoaiNV() const;
        ll TinhLuong() const;
};

LapTrinhVien::LapTrinhVien(string ma_nv, string ten_nv, int tuoi_nv, string sdt, string email, ll luong_co_ban, int so_gio_lam_viec)
    : NhanVien(ma_nv, ten_nv, tuoi_nv, sdt, email, luong_co_ban), so_gio_lam_viec(so_gio_lam_viec) {}


int LapTrinhVien::GetSoGioLamViec() const { return so_gio_lam_viec; }

void LapTrinhVien::SetSoGioLamViec(int so_gio_lam_viec) { this->so_gio_lam_viec = so_gio_lam_viec; }

void LapTrinhVien::Nhap() 
{
    NhanVien::Nhap();
    cout << "Nhap so gio lam viec: ";
    cin >> so_gio_lam_viec;
}

void LapTrinhVien::Xuat() const 
{
    NhanVien::Xuat();
    cout << "+ So gio lam viec: " << so_gio_lam_viec << endl;
}

string LapTrinhVien::GetLoaiNV() const 
{
    return "Lap Trinh Vien";
}

ll LapTrinhVien::TinhLuong() const 
{
    return luong_co_ban + so_gio_lam_viec * 200000;
}